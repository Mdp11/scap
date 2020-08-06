#ifndef ACTIONS_HPP
#define ACTIONS_HPP

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
    void execute(MusicPlayer* player) override;
};

class Stop : public Action
{
public:
    void execute(MusicPlayer* player) override;
};

class Quit : public Action
{
public:
    void execute(MusicPlayer* player) override;
};

#endif //ACTIONS_HPP