#include "actions.hpp"
#include "music_player.hpp"

void PlayPause::execute(MusicPlayer* player)
{ 
    auto channel = player->getChannel();
    bool paused;
    channel->getPaused(&paused);
    paused ? channel->setPaused(false) : channel->setPaused(true);
}

void Stop::execute(MusicPlayer* player)
{ 
    player->getChannel()->stop();
}

void Quit::execute(MusicPlayer* player)
{
    player->signalShutDown();
}