#include "playlist.hpp"

std::vector<std::string> Playlist::getCurrentSongs()
{
    std::vector<std::string> list;
    std::lock_guard<std::mutex> lock(mtx_);
    for(const auto& song : queue_)
    {
        list.push_back(song->getFilePath());
    }
    return getCurrentSongs();
}