#ifndef MESSAGE_QUEUE_HPP
#define MESSAGE_QUEUE_HPP

#include <condition_variable>
#include <deque>
#include <mutex>

template<typename T>
class MessageQueue
{
public:
    void push(T msg)
    {
        std::lock_guard<std::mutex> lock{mtx_};
        queue_.emplace_back(std::move(msg));
        msg_available_.notify_one();
    }

    T pop()
    {
        std::unique_lock<std::mutex> lock{mtx_};
        msg_available_.wait(lock, [this] { return !queue_.empty(); });
        auto msg = std::move(queue_.front());
        queue_.pop_front();
        return msg;
    }

protected:
    std::deque<T> queue_;
    std::mutex mtx_;
    std::condition_variable msg_available_;

};

#endif //MESSAGE_QUEUE_HPP