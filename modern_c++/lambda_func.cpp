#include <chrono>

using Time = std::chrono::steady_clock::time_point;
// enum class
enum class Sound
{
    Beep,
    Siren,
    Whistle
};

using Duration = std::chrono::steady_clock::duration;

void setAlarm(Time t, Sound s, Duration d);

auto setSoundL = [](Sound s)
{
    using namespace std::chrono;
    using namespace std::literals;

    // setAlarm(steady_clock::now() + hours(1), s, seconds(30));
    setAlarm(steady_clock::now() + 1h, s, 30s);
};

using namespace std::chrono;
using namespace std::literals;
#include <functional>

using namespace std::placeholders;

auto setSoundB = std::bind(setAlarm, steady_clock::now() + 1h, _1, 30s);

auto setSoudB = std::bind(setAlarm, std::bind(std::plus<>(), steady_clock::now(), 1h), _1, 30s);
// int lowVal = 1, highVal = 10;

// auto betweenL = [lowVal, highVal](const auto &val)
// {
//     return lowVal <= val && val <= highVal;
// };
#include <type_traits>

template <typename T>
typename std::remove_reference<T>::type&& move(T&& param){
    using ReturnType = typename std::remove_reference<T>::type &&; // alias declaration

    return static_cast<ReturnType>(param);
}

template<typename T>
decltype(auto) move(T&& param){
    using ReturnType = remove_reference_t<T> &&;
    return static_cast<ReturnType>(param);
}  