#include <regex>
#include <iostream>

#include "input_helper.hpp"
#include "music_player.hpp"
#include "mp3.hpp"

void inputHelper::PrintHelp()
{
    //TODO: add proper help section
    std::cout << "Help!" << std::endl;
}

bool inputHelper::IsValidCommand(const std::string& cmd)
{
    //TODO: add current song info and list playlist command and remove from playlist
    return cmd == "q" || cmd == "l" || cmd == "p";
}

void inputHelper::ProcessCommand(const std::string& cmd, MusicPlayer* player)
{
    if(!IsValidCommand(cmd))
    {
        PrintHelp();
        return;
    }
    if(cmd == "p")
    {
        std::string audio_file_name{};
        std::cout << "Insert audio file path: " << std::endl;
        std:: cin >> audio_file_name;
        std::cout << "Enqueing song " << audio_file_name << std::endl;
        std::unique_ptr<Mp3> audio = std::make_unique<Mp3>(audio_file_name);
        player->enqueue(std::move(audio));
    }
}