#ifndef _MUSIC_PLAYER_HPP_
#define _MUSIC_PLAYER_HPP_

#include <string>
#include <memory>
#include "fmod.hpp"

#include "playlist.hpp"
#include "actions.hpp"
#include "audio.hpp"

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
        void addAction(std::unique_ptr<Action> action) { actions_.push(std::move(action)); }

        std::string getCurrentSongInfo();
        void signalShutDown();

    private:
        void checkFmodOperation(const std::string &message, FMOD_RESULT result);

        FMOD::System* system_ {nullptr};
        FMOD::ChannelGroup* channelGroup_ {nullptr};
        FMOD::Sound * currentsound_ {nullptr};
        FMOD::Channel* channel_ {nullptr};

        Playlist playlist_;
        ActionQueue actions_;

        std::unique_ptr<Audio> current_audio_;
        bool shutdown_{false};

};

#endif