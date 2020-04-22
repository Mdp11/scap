#include <iostream>
#include "input_helper.hpp"
#include "music_player.hpp"
#include "fmod.h"

int main(int argc, char *argv[])
{
    std::string cmd{};
    while(cmd != "q")
    {
        cmd.clear();
        inputHelper::PrintHelp();
        std::cin >> cmd;
        if(inputHelper::IsValidCommand(cmd))
        {
            inputHelper::ProcessCommand(cmd);
            MusicPlayer player{};
        }
    }
    return 0;
}
