// #include "accum1.hpp"
#include "accum2.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    int num[] = {1, 2, 3, 4, 5};
    std::cout << "the average value of the integer values is "
              << accum(num, num + 5) / 5 << '\n';

    char name[] = "templates";
    int length = sizeof(name) - 1;
    std::cout << "the average value of the charater s in \""
              << name << "\" is "
              << accum(name, name + length) / length
              << '\n';

    return 0;
}
