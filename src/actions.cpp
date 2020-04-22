#include "actions.hpp"

bool ActionQueue::AreActionsRequested()
{
    std::lock_guard lock{mtx_};
    return !queue_.empty();
}