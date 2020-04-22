#ifndef _ACTION_QUEUE_HPP_
#define _ACTION_QUEUE_HPP_

#include "message_queue.hpp"
#include <memory>

class Action;

class ActionQueue : public MessageQueue<std::unique_ptr<Action>>
{
    public:
        bool AreActionsRequested();
};

#endif