#include <iostream>
#include <thread>
#include "music_player.hpp"
#include "fmod_errors.h"

template <typename T>
T MessageQueue<T>::pop()
{
    std::unique_lock lock{mtx_};
    msg_available_.wait(lock, [this]{ return !queue_.empty(); });
    auto msg = std::move(queue_.front());
    queue_.pop();
    return msg;
}

template <typename T>
void MessageQueue<T>::push(T&& msg)
{
    std::lock_guard lock{mtx_};
    queue_.emplace(std::move(msg));
    msg_available_.notify_one();
}

template <typename T>
void MessageQueue<T>::notify()
{
    std::lock_guard lock{mtx_};
    msg_available_.notify_one();
}

void MusicPlayer::checkFmodOperation(const std::string &message, FMOD_RESULT result)
{
    if (result != FMOD_OK) {
        throw(std::runtime_error(message + " : " + std::to_string(result) + " " + FMOD_ErrorString(result)));
    }
}

MusicPlayer::MusicPlayer()
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


void MusicPlayer::run()
{
    while(!shutdown_)
    {
        auto audio = audio_queue_.pop();
        if(shutdown_)
            break;
        
        FMOD_RESULT result;
        std::cout << "Playing... " << audio << std::endl;
        FMOD::Sound *sound = nullptr;
        system_->createSound(audio.c_str(), FMOD_DEFAULT, nullptr, &sound);

        // Play the sound.
        result = system_->playSound(sound, nullptr, false, &channel_);
        checkFmodOperation("FMOD: Failed to play sound", result);

        // Assign the channel to the group.
        result = channel_->setChannelGroup(channelGroup_);
        checkFmodOperation("FMOD: Failed to set channel group on", result);

        // Set a callback on the channel.
        // This works.
        // channel_->setCallback(&channelGroupCallback);
        // if (!succeededOrWarn("FMOD: Failed to set callback for sound", result))
        //     return 1;

        bool isPlaying = false;
        do {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));

            channel_->isPlaying(&isPlaying);

            system_->update();
        } while (isPlaying);
    }

}

void MusicPlayer::signalShutDown() 
{ 
    shutdown_ = true;
    audio_queue_.push("shutdown");
}
