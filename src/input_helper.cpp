#include "input_helper.h"
#include <iostream>

void inputHelper::PrintHelp()
{
    std::cout << "Help!" << std::endl;
}

bool inputHelper::IsValidCommand(const std::string& cmd)
{
    return cmd == "q" || cmd == "l";
}

void inputHelper::ProcessCommand(const std::string& cmd)
{
    std::cout << "Processing command " << cmd << " " << std::endl;
}