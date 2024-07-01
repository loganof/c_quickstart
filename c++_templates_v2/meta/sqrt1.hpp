

// primary template
template <int N, int LO = 1, int HI = N>
struct Sqrt
{
    static constexpr auto mid = (LO + HI + 1) / 2;
    static constexpr auto value = (N < mid * mid) ? Sqrt<N, LO, mid - 1>::value : Sqrt<N, mid, HI>::value;
};

// partial specialization
template <int N, int M>
struct Sqrt<N, M, M>
{
    static constexpr auto value = M;
};
