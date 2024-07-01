#include <chrono>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::cout << "秒:" << std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now().time_since_epoch()).count() << std::endl;
    std::cout << "毫秒:" << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count() << std::endl;

    std::cout << "微秒:" << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now().time_since_epoch()).count() << std::endl;
    std::cout << "纳秒:" << std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now().time_since_epoch()).count() << std::endl;
    std::cout << "默认:" << std::chrono::steady_clock::now().time_since_epoch().count() << std::endl;
    return 0;
}
