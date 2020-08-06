#ifndef PLAYLIST_HPP
#define PLAYLIST_HPP

#include <memory>
#include <string>
#include <vector>

#include "message_queue.hpp"
#include "audio.hpp"

class Playlist : public MessageQueue<std::unique_ptr<Audio>>
{
public:
    std::vector<std::string> getCurrentSongs();
};

#endif //PLAYLIST_HPP