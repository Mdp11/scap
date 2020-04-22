#include <regex>
#include <iostream>
#include <future>

#include "input_helper.hpp"
#include "music_player.hpp"
#include "actions.hpp"
#include "mp3.hpp"

void inputHelper::PrintHelp()
{
    std::cout << "Available commands: " << std::endl;
    std::cout << "  - a (Add new audio to the playlist, audio path will be requested)" << std::endl;
    std::cout << "  - n (play Next audio in the playlist)" << std::endl;
    std::cout << "  - c (print Currently played audio)" << std::endl;
    std::cout << "  - p (Pause/Play)" << std::endl;
    std::cout << "  - h (Help, show this text)" << std::endl;
    std::cout << "  - q (Quit)" << std::endl;
}

bool inputHelper::IsValidCommand(const std::string& cmd)
{
    //TODO: add current song info and list playlist command and remove from playlist and go to next song in queue and stop current song
    return cmd == "q" || cmd == "c" || cmd == "p" || cmd == "a" || cmd == "n";
}

void inputHelper::ProcessCommand(const std::string& cmd, MusicPlayer* player)
{
    if(!IsValidCommand(cmd))
    {
        system("clear");
        if(cmd != "h")
            std::cout << "Invalid command!" << std::endl;
        PrintHelp();
        return;
    }
    else if(cmd == "a")
    {
        std::string audio_file_name{};
        std::cout << "Insert audio file path: " << std::endl;
        std:: cin >> audio_file_name;
        std::cout << "Enqueing song " << audio_file_name << std::endl;
        std::unique_ptr<Mp3> audio = std::make_unique<Mp3>(audio_file_name);
        player->enqueue(std::move(audio));
    }
    else if(cmd == "c")
    {
        auto current_song_info_ = std::async(std::launch::async, &MusicPlayer::getCurrentSongInfo, player);
        std::cout << "Currently playing " << current_song_info_.get() << std::endl;
    }
    else if(cmd == "p")
    {
        player->addAction(std::make_unique<PlayPause>());
    }
    else if(cmd == "n")
    {
        player->addAction(std::make_unique<Stop>());
    }
    else if(cmd == "q")
    {
        player->addAction(std::make_unique<Quit>());
    }
    system("clear");
}