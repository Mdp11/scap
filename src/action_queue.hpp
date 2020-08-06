#ifndef _ACTION_QUEUE_HPP_
#define _ACTION_QUEUE_HPP_

#include <memory>

#include "message_queue.hpp"

class Action;

class ActionQueue : public MessageQueue<std::unique_ptr<Action>>
{
public:
    bool AreActionsRequested();
};

#endif