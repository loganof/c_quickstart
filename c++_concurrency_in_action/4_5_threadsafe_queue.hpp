/*
 * @Author: pengzhongchao pengzhongchao@senseauto.com
 * @Date: 2023-08-02 09:03:18
 * @LastEditors: pengzhongchao pengzhongchao@senseauto.com
 * @LastEditTime: 2023-08-30 16:30:29
 * @FilePath: /c++Pro/c++_concurrency_in_action/4_5_threadsafe_queue.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef main_4_5
#define main_4_5

#include <queue>
#include <memory>
#include <mutex>
#include <condition_variable>

template <typename T>
class threadsafe_queue
{
private:
    mutable std::mutex mut; // 互斥量必须是可变的
    std::queue<T> data_queue;
    std::condition_variable data_cond;

public:
    threadsafe_queue() = default;                   // 生成默认构造函数
    threadsafe_queue(const threadsafe_queue &other) // 拷贝构造
    {
        std::lock_guard<std::mutex> lk(other.mut);
        data_queu = other.data_queue;
    }
    void push(T new_value)
    {
        std::lock_guard<std::mutex> lk(mut);
        data_queue.push(new_value);
        data_cond.notify_one();
    }
    void wait_and_pop(T &val)
    {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk, [this]
                       { return !data_queue.empty(); });
        val = data_queue.front();
        data_queue.pop();
    }

    std::shared_ptr<T> wait_and_pop()
    {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk, [this]
                       { return !this->data_queue.empty(); });
        std::shared_ptr<T> ret = std::make_shared<T>(data_queue.front());
        data_queue.pop();
        return ret;
    }

    bool try_pop(T &value)
    {
        std::lock_guard<std::mutex> lk(mut);
        if (data_queue.empty())
            return false;
        value = data_queue.front();
        data_queue.pop();
        return value;
    }

    std::shared_ptr<T> try_pop()
    {
        std::lock_guard<std::mutex> lk(mut);
        if (data_queue.empty())
            return std::make_shared<T>();
    }
};

#endif