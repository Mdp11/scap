#ifndef _INPUT_HELPER_HPP_
#define _INPUT_HELPER_HPP_

#include <string>
#include <unordered_map>
#include <functional>

class MusicPlayer;

class IOHandler
{
    public:
        IOHandler(MusicPlayer* player);
        void ProcessCommand(const std::string& cmd);
    private:
        void PrintHelp();
        std::unordered_map<std::string, std::function<void(MusicPlayer*)>> commands_;
        MusicPlayer* player_;


};

#endif