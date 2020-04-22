#ifndef _AUDIO_HPP_
#define _AUDIO_HPP_

#include <string>

class Audio
{
    public:
        Audio(std::string s) : path_(s){} ;
        virtual void getInfo() = 0;
        virtual std::string getFilePath() { return path_; }
    protected:
        std::string path_;
};

#endif