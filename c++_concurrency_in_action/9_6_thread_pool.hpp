#include "6_2_threadsafe_queue.h"
#include "9_2_function_wrapper.hpp"
#include <atomic>
#include <future>

class thread_pool
{
    std::atomic_bool done{false};
    threadsafe_queue<function_wrapper> pool_worke_queue;
    typedef std::queue<function_wrapper> local_queue_type;
    static thread_local std::unique_ptr<local_queue_type> local_work_queue;

    void worker_thread()
    {
        local_work_queue.reset(new local_queue_type);
        while (!done)
        {
            run_pending_task();
        }
    }

public:
    template <typename FunctionType>
    std::future<typename std::result_of<FunctionType()>::type>
    sumit(FunctionType f)
    {
    }

    void run_pending_task()
    {
        function_wrapper task;
    }
};