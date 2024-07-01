#ifndef RATIO_HPP
#define RATIO_HPP
template <unsigned N, unsigned D = 1>
struct Ratio
{
    static constexpr unsigned num = N;
    static constexpr unsigned den = D;
    using Type = Ratio<num, den>;
};

// template <typename R1, typename R2>
// using RatioAdd = typename RatioAddImpl<R1, R2>::Type;
#endif