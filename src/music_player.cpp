#include <iostream>
#include <thread>

#include "fmod_errors.h"

#include "audio.hpp"
#include "music_player.hpp"

void MusicPlayer::checkFmodOperation(const std::string& message, FMOD_RESULT result)
{
    if (result != FMOD_OK)
    {
        throw (std::runtime_error(message + " : " + std::to_string(result) + " " + FMOD_ErrorString(result)));
    }
}

MusicPlayer::MusicPlayer()
{
    try
    {
        FMOD_RESULT result;

        result = FMOD::System_Create(&system_);
        checkFmodOperation("FMOD: Failed to create system object", result);

        result = system_->init(512, FMOD_INIT_NORMAL, nullptr);
        checkFmodOperation("FMOD: Failed to initialise system object", result);

        result = system_->createChannelGroup("inGameSoundEffects", &channelGroup_);
        checkFmodOperation("FMOD: Failed to create in-game sound effects channel group", result);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception while creating MusicPlayer: " << e.what() << std::endl;
        std::cout << "Aborting." << std::endl;
    }

    actions_handler_ = std::thread{&MusicPlayer::processActions, this};
}

MusicPlayer::~MusicPlayer()
{
    actions_handler_.join();
    channelGroup_->release();
    system_->release();
}

void MusicPlayer::run()
{
    while (!shutdown_)
    {
        current_audio_ = playlist_.pop();
        if (shutdown_)
        {
            break;
        }

        FMOD_RESULT result;
        FMOD::Sound* sound = nullptr;
        system_->createSound(current_audio_->getFilePath().c_str(), FMOD_DEFAULT, nullptr, &sound);

        try
        {
            result = system_->playSound(sound, nullptr, false, &channel_);
            checkFmodOperation("FMOD: Failed to play sound", result);

            result = channel_->setChannelGroup(channelGroup_);
            checkFmodOperation("FMOD: Failed to set channel group on", result);

            std::cout << "Playing \"" << current_audio_->getFilePath() << "\"..." << std::endl;
            bool isPlaying = false;
            do
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
                channel_->isPlaying(&isPlaying);
                system_->update();
            } while (isPlaying && !shutdown_);
        }
        catch (const std::exception& e)
        {
            std::cout << e.what() << std::endl;
            std::cout << "Possible causes:" << std::endl;
            std::cout << "  - requested file does not exist" << std::endl;
            std::cout << "  - requested file is not an audio file" << std::endl;
            std::cout << "  - your system has problems with sound drivers" << std::endl;
        }
        sound->release();
        current_audio_.reset();
    }
}

void MusicPlayer::processActions()
{
    while (!shutdown_)
    {
        auto action = actions_.pop();
        action->execute(this);
    }
}

std::string MusicPlayer::getCurrentSongInfo()
{
    return current_audio_ ? current_audio_->getFilePath() : "nothing";
}

void MusicPlayer::signalShutDown()
{
    shutdown_ = true;
    playlist_.push(std::make_unique<Audio>("shutdown"));
}
