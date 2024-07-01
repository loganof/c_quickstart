#ifndef OBJECTCOUNTER
#define OBJECTCOUNTER

#include <cstddef>

template <typename CounterType>
class ObjectCounter
{
private:
    inline static std::size_t count = 0;

protected:
    ObjectCounter()
    {
        ++count;
    }

    ObjectCounter(ObjectCounter<CounterType> const &)
    {
        ++count;
    }

    ObjectCounter(ObjectCounter<CounterType> &&)
    {
        ++count;
    }

    ~ObjectCounter()
    {
        --count;
    }

public:
    static std::size_t live()
    {
        return count;
    }
};

#endif
