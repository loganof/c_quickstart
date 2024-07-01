#include "duration.hpp"
#include "ratioadd.hpp"

template <typename T1, typename U1, typename T2, typename U2>
auto constexpr operator+(Duration<T1, U1> const &lhs, Duration<T2, U2> const &rhs)
{
    using VT = Ratio<1, RatioAdd<U1, U2>::den>;
    auto val = lhs.value() * VT::den / U1::den * U1::num +
               rhs.value() * VT::den / U2::den * U2::num;
    return Duration<decltype(val), VT>(val);
}
int main(int argc, char const *argv[])
{
    int x = 42;
    int y = 77;
    auto a = Duration<int, Ratio<1, 1000>>(x);
    auto b = Duration<int, Ratio<2, 3>>(y);
    auto c = a + b;
    return 0;
}
