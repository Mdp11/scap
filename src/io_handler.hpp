#ifndef IO_HANDLER_HPP
#define IO_HANDLER_HPP

#include <functional>
#include <string>
#include <unordered_map>

class MusicPlayer;

class IOHandler
{
public:
    explicit IOHandler(MusicPlayer* player);
    void ProcessCommand(const std::string& cmd);
    static void PrintHelp();

private:
    std::unordered_map<std::string, std::function<void(MusicPlayer*)>> commands_;
    MusicPlayer* player_;

};

#endif //IO_HANDLER_HPP