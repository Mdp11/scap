#include <iostream>
#include <future>

#include "audio.hpp"
#include "io_handler.hpp"
#include "music_player.hpp"

IOHandler::IOHandler(MusicPlayer* player) : player_(player)
{
    commands_ = {
        {"a", [](MusicPlayer* player){  
                                        std::string audio_file_name{};
                                        std::cout << "Insert audio file path: ";
                                        std:: cin >> audio_file_name;
                                        std::unique_ptr<Audio> audio = std::make_unique<Audio>(audio_file_name);
                                        player->enqueue(std::move(audio));
                                     }
        },
        
        {"n", [](MusicPlayer* player){ player->addAction(std::make_unique<Stop>());}},
        
        {"c", [](MusicPlayer* player){
                                        auto current_song_info_ = std::async(std::launch::async, &MusicPlayer::getCurrentSongInfo, player);
                                        std::cout << "Currently playing " << current_song_info_.get() << std::endl;
                                     }
        },
        
        {"p", [](MusicPlayer* player){ player->addAction(std::make_unique<PlayPause>()); }},

        {"x", [this](MusicPlayer* player){ PrintHelp(); }},
        
        {"q", [](MusicPlayer* player){ player->addAction(std::make_unique<Quit>()); }},
    };
}

void IOHandler::PrintHelp()
{
    system("clear");
    std::cout << "##################SCAP##################" << std::endl;
    std::cout << "Available commands: " << std::endl;
    std::cout << "  - a (Add new audio to the playlist, audio path will be requested)" << std::endl;
    std::cout << "  - n (play Next audio in the playlist)" << std::endl;
    std::cout << "  - c (print Currently played audio)" << std::endl;
    std::cout << "  - p (Pause/Play)" << std::endl;
    std::cout << "  - x (clear screen)" << std::endl;
    std::cout << "  - q (Quit)" << std::endl;
    std::cout << "########################################" << std::endl;
}

void IOHandler::ProcessCommand(const std::string& cmd)
{
    if(commands_.find(cmd) != commands_.end())
    {
        commands_[cmd](player_);
    }
    else
    {   
        std::cout << "Invalid command!" << std::endl;

    }
    
}

        