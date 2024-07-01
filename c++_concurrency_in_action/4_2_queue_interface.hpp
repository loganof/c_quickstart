#include <deque>

template <typename T, class Container = std::deque<T>>
class queue
{
public:
    explicit queue(const Container &);          // 拷贝构造
    explicit queue(Container && = Container()); // 移动构造
};
