#ifndef _ACTIONS_HPP_
#define _ACTIONS_HPP_

#include <memory>

#include "fmod.hpp"

class MusicPlayer;

class Action
{
    public:
        virtual void execute(MusicPlayer* player) = 0;
};

class PlayPause : public Action
{
    virtual void execute(MusicPlayer* player);
};

class Stop : public Action
{
    virtual void execute(MusicPlayer* player);
};

class Quit : public Action
{
    virtual void execute(MusicPlayer* player);
};

#endif