#ifndef _MP3_HPP_
#define _MP3_HPP_

#include "audio.hpp"

class Mp3 : public Audio
{
    public:
        Mp3(std::string s);
        virtual void getInfo() override;
    private:
        std::string title_;
        std::string author_;

};

#endif