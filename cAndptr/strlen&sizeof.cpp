#include <iostream>

int main(int argc, char const *argv[])
{
    const char *str = "hello";
    std::cout << sizeof(str) << std::endl;
    std::cout << strlen(str) << std::endl;
    return 0;
}
