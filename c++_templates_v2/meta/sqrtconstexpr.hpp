
template <typename T>
constexpr T sqrt(T x)
{
    if (x <= 1)
    {
        return x;
    }
    T lo = 0, hi = x;

    for (;;)
    {
        auto mid = (hi + lo) / 2, midSquared = mid * mid;
        if (lo + 1 >= hi || midSquared == x)
        {
            return mid;
        }

        if (midSquared < x)
        {
            lo = mid;
        }
        else
        {
            hi = mid;
        }
    }
}

static_assert(sqrt(25) == 5, "");
static_assert(sqrt(40) == 6, "");

std::array<int, sqrt(40) + 1> arr;
long long l = 53478;
std::cout << sqrt(l) << '\n';