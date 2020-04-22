#include "mp3.hpp"
#include <iostream>

Mp3::Mp3(std::string s) : Audio(s)
{
    //TODO: Read tags from mp3 file;
}

void Mp3::Mp3::getInfo()
{
    std::cout << path_ << std::endl;
}