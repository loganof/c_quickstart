// 线程安全stack
#include <exception>
#include <stack>
#include <mutex>

struct empty_stack : std::exception
{
    const char *what() const throw();
};

template <typename T>
class threadsafe_stack
{
private:
    std::stack<T> data;
    mutable std::mutex m;

public:
    // 默认构造
    threadsafe_stack() {}
    // 拷贝构造
    threadsafe_stack(const threadsafe_stack &other)
    {
        // std::lock_guard RAII原理
        std::lock_guard<std::mutex> lock(other.m);
        data = other.data;
    }
    // 赋值操作符
    threadsafe_stack &operator=(const threadsafe_stack &) = delete;

    void push(T new_value)
    {
        std::lock_guard<std::mutex> lock(m);
        data.push(std::move(new_value));
    }

    std::shared_ptr<T> pop()
    {
        std::lock_guard<std::mutex> lock(m);
        if (data.empty())
            throw empty_stack();
        value = std::move(data.top());
        data.pop();
    }

    bool empty() const
    {
        std::lock_guard<std::mutex> lock(m);
        return data.empty();
    }
};