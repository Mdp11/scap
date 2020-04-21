#include <iostream>
#include "input_helper.h"
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
        }
    }
    return 0;
}
