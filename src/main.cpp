#include <iostream>
#include <thread>

#include "input_helper.hpp"
#include "music_player.hpp"

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
    t.join();
    delete player;
    return 0;
}
