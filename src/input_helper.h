#ifndef _INPUT_HELPER_H_
#define _INPUT_HELPER_H_

#include <string>

namespace inputHelper{
    void PrintHelp();
    bool IsValidCommand(const std::string& cmd);
    void ProcessCommand(const std::string& cmd);
}

#endif