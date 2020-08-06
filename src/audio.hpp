#ifndef AUDIO_HPP
#define AUDIO_HPP

#include <string>
#include <utility>
#include <utility>

class Audio
{
public:
    explicit Audio(std::string s) : path_{std::move(s)} {};
    virtual std::string getInfo() { return path_; };
    virtual std::string getFilePath() { return path_; }
protected:
    std::string path_;
};

#endif //AUDIO_HPP