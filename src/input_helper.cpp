#include "input_helper.h"
#include <iostream>

void input_helper::PrintHelp()
{
    std::cout << "Help!" << std::endl;
}

bool input_helper::IsValidCommand(const std::string& cmd)
{
    return cmd == "q" || cmd == "l";
}

void input_helper::ProcessCommand(const std::string& cmd)
{
    std::cout << "Processing command " << cmd << " " << std::endl;
}