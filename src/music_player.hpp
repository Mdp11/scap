#ifndef _MUSIC_PLAYER_HPP_
#define _MUSIC_PLAYER_HPP_

#include <string>
#include <queue>
#include <mutex>
#include <condition_variable>
#include "fmod.hpp"

template <typename T>
class MessageQueue 
{
    public:
        void Push(T&& msg);
        T Pop();
        void PrintContent();
    
    private:
        std::queue<T> queue_;
        std::mutex mtx_;
        std::condition_variable msg_available_;

};

//TODO Inherit from Threadable
class MusicPlayer
{
    public:
        MusicPlayer();

    private:
        void CheckFmodOperation(const std::string &message, FMOD_RESULT result);
        void run();

        FMOD::System* system_ {nullptr};
        FMOD::ChannelGroup* channelGroup_ {nullptr};
        FMOD::Sound * currentsound_ {nullptr};
        FMOD::Channel* channel_ {nullptr};
        MessageQueue<std::string> audio_queue_;

};

#endif