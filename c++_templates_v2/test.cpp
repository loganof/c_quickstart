// template <typename T>
// typename T::ElementT at(T a, int i)
// {
//     return a[i];
// }

// void f(int *p)
// {
//     int x = at(p, 7);
// }

#include <iostream>

template <typename T, typename... Types>
void print(T firstArg, Types... args)
{
    std::cout << sizeof...(Types) << '\n';
    std::cout << sizeof...(arg) << '\n';
}

template <typename T, typename... Types>
void print(T firstArg, Types... args)
{
    std::cout << firstArg << '\n';
    if (sizeof...(args) > 0)
    {
        print(args...);
    }
}

template <typename... T>
auto foldSum(T... s)
{
    return (... + s);
}

template <typename... Types>
void print(Types const &...args)
{
    (std::cout << ... << args) << '\n';
}

auto sp = std::make_shared<std::complex<float>>(4.2, 7.7);
std::thread t(foo, 42, "hello");

template <typename T>
union AllocChunk
{
    T object;
    unsigned char bytes[sizeof(T)];
};

template <typename T>
class Box;

template <typename T>
class Q
{
    using Type = typename T::Type;
};
Q<int> *p = 0;

template <typename T>
T v = T::defaut_value();

template <typename T>
class CuriousBase
{
};

class Curious : public CuriousBase<Curious> // curiously recurring template pattern(CRTP)
{
};

template <typename T>
void f(T &&x)
{
    auto p = &x;
    auto q = std::addressof(x);
}

template <typename T>
void foo()
{
    T x{}; // value initialization
}
#include <stack>
template <typename T>
void report_top(Stack<T> const &, int number = 10);

template <typename T>
void fill(Array<T> &, T const & = T{});