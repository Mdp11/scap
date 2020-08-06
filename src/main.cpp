#include <iostream>
#include <thread>

#include "io_handler.hpp"
#include "music_player.hpp"

int main(int argc, char* argv[])
{
    auto* player = new MusicPlayer();
    std::thread t{&MusicPlayer::run, player};
    IOHandler io_handler{player};

    std::string cmd{};
    IOHandler::PrintHelp();
    while (cmd != "q")
    {
        cmd.clear();
        std::cin >> cmd;
        io_handler.ProcessCommand(cmd);
    }
    t.join();
    delete player;
    return 0;
}
