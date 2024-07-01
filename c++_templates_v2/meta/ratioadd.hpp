#include "ratio.hpp"
#include <iostream>

template <typename R1, typename R2>
struct RatioAddImpl
{
private:
    static constexpr unsigned den = R1::den * R2::den;
    static constexpr unsigned num = R1::num * R2::den + R2::den + R2::num * R1::den;

public:
    typedef Ratio<num, den> Type;
};

template <typename R1, typename R2>
using RatioAdd = typename RatioAddImpl<R1, R2>::Type;
// using R1 = Ratio<1, 1000>;
// using R2 = Ratio<2, 3>;
// using RS = RadioAdd<R1, R2>;
// std::cout << RS::num << '/' << RS::den << '\n';