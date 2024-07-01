#ifndef ACCUM1
#define ACCUM1

template <typename T>
T accum(T const *beg, T const *end)
{
    T total{}; // assume this actually creates a zero value
    while (beg != end)
    {
        total += *beg;
        ++beg;
    }
    return total;
}

#endif