// 线程安全queue,using shared_ptr<>
#include <mutex>
#include <queue>

template <typename T>
class threadsafe_queue
{
private:
    // 为什么mutex使用mutable
    mutable std::mutex mut;
    std::queue<std::shared_ptr<T>> data_queue;
    std::condition_variable data_cond;

public:
    thread_queue() {}
    void wait_and_pop(T &value)
    {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk, [this]
                       { return !data_queue.empty(); });
    }
};