#include <iostream>
#include "input_helper.hpp"
#include "music_player.hpp"
#include "thread"
#include "fmod.h"

int main(int argc, char *argv[])
{
    MusicPlayer* player = new MusicPlayer();
    std::thread t{&MusicPlayer::run, player};
    
    std::string cmd{};
    inputHelper::PrintHelp();
    while(cmd != "q")
    {
        cmd.clear();
        std::cin >> cmd;
        inputHelper::ProcessCommand(cmd, player);
    }
    player->signalShutDown();
    t.join();
    delete player;
    return 0;
}
