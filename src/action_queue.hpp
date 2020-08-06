#ifndef ACTION_QUEUE_HPP
#define ACTION_QUEUE_HPP

#include <memory>

#include "message_queue.hpp"

class Action;

class ActionQueue : public MessageQueue<std::unique_ptr<Action>>
{
public:
    bool AreActionsRequested();
};

#endif //ACTION_QUEUE_HPP