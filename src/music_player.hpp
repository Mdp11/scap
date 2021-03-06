#ifndef MUSIC_PLAYER_HPP
#define MUSIC_PLAYER_HPP

#include <atomic>
#include <memory>
#include <string>
#include <thread>

#include "fmod.hpp"

#include "audio.hpp"
#include "action_queue.hpp"
#include "actions.hpp"
#include "playlist.hpp"

class Action;

class MusicPlayer
{
private:
    Playlist playlist_{};
    ActionQueue actions_{};

    std::unique_ptr<Audio> current_audio_{};
    std::atomic<bool> shutdown_{false};

    std::thread actions_handler_;

    FMOD::System* system_{nullptr};
    FMOD::ChannelGroup* channelGroup_{nullptr};
    FMOD::Sound* current_sound_{nullptr};
    FMOD::Channel* channel_{nullptr};

    void processActions();
    static void checkFmodOperation(const std::string& message, FMOD_RESULT result);

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
    FMOD::Channel* getChannel() { return channel_; }

    std::string getCurrentSongInfo();
    void signalShutDown();

};

#endif //MUSIC_PLAYER_HPP