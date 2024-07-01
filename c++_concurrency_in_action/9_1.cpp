#include <iostream>
#include "9_1_thread_pool.hpp"

int main(int argc, char const *argv[])
{
    auto funcA = []()
    {
        for (size_t i = 0; i < 100; i++)
        {
            std::cout << i << std::endl;
        }
    };
    thread_pool pool;
    pool.submit(funcA);
    pool.submit(funcA);
    return 0;
}