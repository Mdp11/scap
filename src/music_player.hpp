#ifndef _MUSIC_PLAYER_HPP_
#define _MUSIC_PLAYER_HPP_

#include <string>

template <typename T>
class MessageQueue 
{

};

//TODO Inherit from Threadable
class MusicPlayer
{
    private:
        void run();

        MessageQueue<std::string> _song_queue;

};

#endif