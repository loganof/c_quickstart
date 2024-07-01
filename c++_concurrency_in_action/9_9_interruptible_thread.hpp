#include <thread>
#include <future>

class interrupt_flag
{
public:
    void set();
    bool is_set();
};
thread_local interrupt_flag this_thread_ingterrupt_flag;

class interruptible_thread
{
    std::thread internal_thread;
    interrupt_flag *flag;

public:
    template <typename FunctionType>
    interruptible_thread(FunctionType f)
    {
        std::promise<interrupt_flag *> p;
    }
};

void interruption_point()
{
    if (this_thread_ingterrupt_flag.is_set())
    {
        // throw thread_interrupted();
    }
}