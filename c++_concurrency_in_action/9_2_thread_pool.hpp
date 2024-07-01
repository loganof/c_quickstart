#include <mutex>
#include "6_2_threadsafe_queue.h"
#include "8_3_join_threads.h"
#include "9_2_function_wrapper.hpp"

class thread_pool
{
private:
    std::atomic_bool done{false};
    threadsafe_queue<function_wrapper> work_queue;
    std::vector<std::thread> threads;
    join_threads joiner{threads};

    void work_thread()
    {
        while (!done)
        {
            function_wrapper task;
            if (work_queue.try_pop(task))
            {
                task();
            }
            else
            {
                std::this_thread::yield();
            }
        }
    }

public:
    thread_pool() = default;
    ~thread_pool() { done = false; }
    // template <typename FunctionType>
    // std::future<std::result_of_t<FunctionType()>>
    // submit(FunctionType f);
    void thread_pool::run_pending_task();
};

void thread_pool::run_pending_task()
{
    function_wrapper task;
    if (work_queue.try_pop(task))
    {
        task();
    }
    else
    {
        std::this_thread::yield();
    }
}

// template <typename FunctionType>
// std::future<std::result_of_t<FunctionType()>> thread_pool::submit(FunctionType f)
// {
//     using result_type = std::result_of_t<FunctionType()>;
//     std::packaged_task<result_type()> task(std::move(f));
//     std::future<result_type> res{task.get_future()};
//     work_queue.push(std::move(task));
//     return res;
// }
