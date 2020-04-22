#ifndef _ACTIONS_HPP_
#define _ACTIONS_HPP_

#include "message_queue.hpp"

enum class ActionType
{
    Pause,
    Unpause,
    RaiseVolume,
    LowerVolume,
    Stop,
    Quit
};

class ActionQueue : public MessageQueue<ActionType>
{
    public:
        bool AreActionsRequested();
};

#endif