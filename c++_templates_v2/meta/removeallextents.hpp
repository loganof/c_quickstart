#include <cstddef>

template <typename T>
struct RemoveAllExtentsT
{
    using Type = T;
};

// partial specializations
template <typename T, std::size_t SZ>
struct RemoveAllExtentsT<T[SZ]>
{
    using Type = typename RemoveAllExtentsT<T>::Type;
};

template <typename T>
struct RemoveAllExtentsT<T[]>
{
    using Type = typename RemoveAllExtentsT<T>::Type;
};

template <typename T>
using RemoveAllExtents = typename RemoveAllExtentsT<T>::Type;