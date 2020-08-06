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
public:
    virtual void execute(MusicPlayer* player) override;
};

class Stop : public Action
{
public:
    virtual void execute(MusicPlayer* player) override;
};

class Quit : public Action
{
public:
    virtual void execute(MusicPlayer* player) override;
};

#endif