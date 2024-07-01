#include <numeric>

template <typename Iterator, typename T>
struct
    accumulate_block
{
    void operator()(Iterator first, Iterator last, T &result)
    {
        result = std::accumulate(first, last, result);
    }
};

#include <vector>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::vector<int> vec(5, 2); // 初始化长度为5，初始值为2的向量

    accumulate_block<std::vector<int>::const_iterator, int> // 如何给模板传入一个迭代器类型
        cal;
    int ret = 0;
    cal(vec.begin(), vec.end(), ret);

    std::cout << ret << "\n";

    return 0;
}
