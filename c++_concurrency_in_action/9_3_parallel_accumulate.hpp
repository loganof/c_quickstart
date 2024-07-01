#include "9_2_thread_pool.hpp"
#include "2_9.hpp"
#include <future>

template <typename Iterator, typename T>
T parralel_accumulate(Iterator first, Iterator last, T init)
{
    const auto length{static_cast<unsigned long>(std::distance(first, last))};
    if (!length)
        return init;
    const auto block_size{25UL};
    const auto num_blocks{(length + block_size - 1) / block_size};
    std::vector<std::future<T>> futures{num_blocks - 1};
    thread_pool pool;
    Iterator block_start{first};
    for (auto i = 0; i < (num_blocks - 1); i++)
    {
        Iterator block_end{block_start};
        std::advance(block_end, block_size);
        futures[i] = pool.sumit([=]
                                { accumulate_block<Iterator, T>()(blocke_start, block_end); });
        block_start = block_end;
    }
    auto last_result = accumulate_block<Iterator, T>()(block_start, last);
    auto result{init};
    for (auto i = 0; i < (num_blocks - 1); i++)
    {
        result += futures[i].get();
    }
    result += last_result;
    return result;
}