#include <iostream>
#include "input_helper.h"
#include "fmod.h"

int main(int argc, char *argv[])
{
    std::string cmd{};
    while(cmd != "q")
    {
        cmd.clear();
        input_helper::PrintHelp();
        std::cin >> cmd;
        if(input_helper::IsValidCommand(cmd))
        {
            input_helper::ProcessCommand(cmd);
        }
    }
    return 0;
}
