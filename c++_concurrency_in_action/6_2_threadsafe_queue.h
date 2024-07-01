// 线程安全queue,using condition variable
#include <mutex>
#include <queue>

template <typename T>
class threadsafe_queue
{
private:
    mutable std::mutex mut;
    std::queue<T> data_queue;
    std::condition_variable data_cond;

public:
    threadsafe_queue() {}
    void push(T new_value)
    {
        // lock_guard使用RAII方式:对象构造时对mutex加锁,析构时对mutex解锁。
        std::lock_guard<std::mutex> lk(mut);
        data_queue.push(std::move(new_value));
        data_cond.notify_one();
    }

    void wait_and_pop(T &value)
    {
        // lock_guard与unique_lock的区别？
        std::unique_lock<std::mutex> lk(mut);
        /* condition_variable带条件的阻塞
            1. wait设置了谓词（predicate),当pred为false时，wait会释放mutex,阻塞当前线程
            2. 其他线程调用notify时，线程唤醒，重新判断pred是否为true.
        */
        data_cond.wait(lk, [this]
                       { return !data_queue.empty(); });
        data_queue.pop();
    }

    std::shared_ptr<T> wait_and_pop()
    {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk, [this]
                       { return !data_queue.empty(); });
        std::shared_ptr<T> res(
            std::make_shared(std::move(data_queue.front())));
        data_queue.pop();
        return res;
    }

    bool try_pop(T &value)
    {
        std::lock_guard<std::mutex> lk(mut);
        if (data_queue.empty())
            return false;
        value = std::move(data_queue.front());
        data_queue.pop();
        return true;
    }

    std::shared_ptr<T> try_pop()
    {
        std::lock_guard<std::mutex> lk(mut);
        if (data_queue.empty())
            return std::shared_ptr<T>();
        std::shared_ptr<T> res(
            std::make_shared<T>(std::move(data_queue.front())));
        data_queue.pop();
        return res;
    }

    bool empty() const
    {
        std::lock_guard<std::mutex> lk(mut);
        return data_queue.empty();
    }
};