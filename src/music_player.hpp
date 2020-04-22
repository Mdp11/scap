#ifndef _MUSIC_PLAYER_HPP_
#define _MUSIC_PLAYER_HPP_

#include <string>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <memory>
#include "fmod.hpp"

#include "audio.hpp"

template <typename T>
class MessageQueue 
{
    public:
        void push(T msg);
        T pop();
        void printContent();
    
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
        ~MusicPlayer();
        MusicPlayer(const MusicPlayer&) = delete;
        MusicPlayer(MusicPlayer&&) = delete;
        MusicPlayer& operator=(const MusicPlayer&) = delete;
        MusicPlayer& operator=(MusicPlayer&&) = delete;

        void run();
        void enqueue(std::unique_ptr<Audio> audio) { playlist_.push(std::move(audio)); }
        std::string getCurrentSongInfo();
        void signalShutDown();

    private:
        void checkFmodOperation(const std::string &message, FMOD_RESULT result);

        FMOD::System* system_ {nullptr};
        FMOD::ChannelGroup* channelGroup_ {nullptr};
        FMOD::Sound * currentsound_ {nullptr};
        FMOD::Channel* channel_ {nullptr};

        MessageQueue<std::unique_ptr<Audio>> playlist_;
        std::unique_ptr<Audio> current_audio_;
        bool shutdown_{false};

};

#endif