#ifndef _ACTIONS_HPP_
#define _ACTIONS_HPP_

#include "message_queue.hpp"
#include <memory>
#include "fmod.hpp"

class Action
{
    public:
        virtual void execute(FMOD::Channel* channel) = 0;
};

class PlayPause : public Action
{
    virtual void execute(FMOD::Channel* channel)
    { 
        bool paused;
        channel->getPaused(&paused);
        paused ? channel->setPaused(false) : channel->setPaused(true);
    }
};

class ActionQueue : public MessageQueue<std::unique_ptr<Action>>
{
    public:
        bool AreActionsRequested();
};

#endif