#include "action_queue.hpp"

bool ActionQueue::AreActionsRequested()
{
    std::lock_guard<std::mutex> lock{mtx_};
    return !queue_.empty();
}