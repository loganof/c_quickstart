#ifndef ACCUM2
#define ACCUM2

#include "accumtraits2.hpp"

template <typename T>
auto accum(T const *beg, T const *end)
{
    using AccT = typename AccumulationTraits<T>::AccT;
    AccT total{};
    while (beg != end)
    {
        total += *beg;
        ++beg;
    }
    return total;
}

#endif