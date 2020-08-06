#include <iostream>

#include "actions.hpp"
#include "music_player.hpp"

void PlayPause::execute(MusicPlayer* player)
{
    auto channel = player->getChannel();
    bool paused;
    channel->getPaused(&paused);
    if (paused)
    {
        std::cout << "Resuming audio..." << std::endl;
        channel->setPaused(false);
    }
    else
    {
        std::cout << "Pausing audio..." << std::endl;
        channel->setPaused(true);
    }

}

void Stop::execute(MusicPlayer* player)
{
    std::cout << "Going to next song in the playlist..." << std::endl;
    player->getChannel()->stop();
}

void Quit::execute(MusicPlayer* player)
{
    player->signalShutDown();
}