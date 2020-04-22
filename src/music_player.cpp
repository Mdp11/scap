#include <iostream>
#include <thread>
#include "fmod_errors.h"

#include "music_player.hpp"
#include "mp3.hpp"

void MusicPlayer::checkFmodOperation(const std::string &message, FMOD_RESULT result)
{
    if (result != FMOD_OK) {
        throw(std::runtime_error(message + " : " + std::to_string(result) + " " + FMOD_ErrorString(result)));
    }
}

MusicPlayer::MusicPlayer()
{
    try
    {
        FMOD_RESULT result;
        // Create the main system object.
        result = FMOD::System_Create(&system_);
        checkFmodOperation("FMOD: Failed to create system object", result);

        // Initialize FMOD.
        result = system_->init(512, FMOD_INIT_NORMAL, nullptr);
        checkFmodOperation("FMOD: Failed to initialise system object", result);

        // Create the channel group.
        result = system_->createChannelGroup("inGameSoundEffects", &channelGroup_);
        checkFmodOperation("FMOD: Failed to create in-game sound effects channel group", result);
    }
    catch(std::exception e)
    {
        std::cout << "Exception while creating MusicPlayer: " << e.what() << std::endl;
        std::cout << "Aborting." << std::endl;
    }
}

MusicPlayer::~MusicPlayer()
{
    channelGroup_->release();
    system_->release();
}


void MusicPlayer::run()
{
    while(!shutdown_)
    {
        current_audio_ = playlist_.pop();
        if(shutdown_)
            break;
        
        FMOD_RESULT result;
        //TODO: change info message
        std::cout << "Playing " << current_audio_->getFilePath();
        std::cout << std::endl;
        FMOD::Sound *sound = nullptr;
        system_->createSound(current_audio_->getFilePath().c_str(), FMOD_DEFAULT, nullptr, &sound);

        try
        {
            // Play the sound.
            result = system_->playSound(sound, nullptr, false, &channel_);
            checkFmodOperation("FMOD: Failed to play sound", result);
            
            // Assign the channel to the group.
            result = channel_->setChannelGroup(channelGroup_);
            checkFmodOperation("FMOD: Failed to set channel group on", result);

            bool isPlaying = false;
            do {
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
                channel_->isPlaying(&isPlaying);
                system_->update();
            } while (isPlaying);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << std::endl;
            std::cout << "The file you tried to play does not exist or it is not an audio file" << std::endl;
        }
        sound->release();
        current_audio_.reset();
    }
}

std::string MusicPlayer::getCurrentSongInfo()
{
    return current_audio_ ? current_audio_->getFilePath() : "No audio currently playing";
}

void MusicPlayer::signalShutDown() 
{ 
    //TODO: handle shutdown better
    shutdown_ = true;
    playlist_.push(std::move(std::make_unique<Mp3>("shutdown")));
}
