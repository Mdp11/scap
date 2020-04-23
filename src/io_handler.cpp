#include "io_handler.hpp"
#include "music_player.hpp"
#include <iostream>
#include <future>
#include "mp3.hpp"

IOHandler::IOHandler(MusicPlayer* player) : player_(player)
{
    commands_ = {
        {"a", [](MusicPlayer* player){  
                                        std::string audio_file_name{};
                                        std::cout << "Insert audio file path: " << std::endl;
                                        std:: cin >> audio_file_name;
                                        std::cout << "Enqueing song " << audio_file_name << std::endl;
                                        std::unique_ptr<Mp3> audio = std::make_unique<Mp3>(audio_file_name);
                                        player->enqueue(std::move(audio));
                                     }
        },
        
        {"n", [](MusicPlayer* player){ player->addAction(std::make_unique<Stop>()); }},
        
        {"c", [](MusicPlayer* player){
                                        auto current_song_info_ = std::async(std::launch::async, &MusicPlayer::getCurrentSongInfo, player);
                                        std::cout << "Currently playing " << current_song_info_.get() << std::endl;
                                     }
        },
        
        {"p", [](MusicPlayer* player){ player->addAction(std::make_unique<PlayPause>()); }},
        
        {"q", [](MusicPlayer* player){ player->addAction(std::make_unique<Quit>()); }},
    };
}

void IOHandler::PrintHelp()
{
    std::cout << "##################SCAP##################" << std::endl;
    std::cout << "Available commands: " << std::endl;
    std::cout << "  - a (Add new audio to the playlist, audio path will be requested)" << std::endl;
    std::cout << "  - n (play Next audio in the playlist)" << std::endl;
    std::cout << "  - c (print Currently played audio)" << std::endl;
    std::cout << "  - p (Pause/Play)" << std::endl;
    std::cout << "  - h (Help, show this text)" << std::endl;
    std::cout << "  - q (Quit)" << std::endl;
    std::cout << "########################################" << std::endl;
    std::cout << "Your command: ";
}

void IOHandler::ProcessCommand(const std::string& cmd)
{
    commands_[cmd](player_);
}

        