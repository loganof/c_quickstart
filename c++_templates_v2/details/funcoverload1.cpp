#include <iostream>
#include "funccoverload1.hpp"

int main(int argc, char const *argv[])
{
    std::cout << f<int *>((int *)nullptr) << std::endl;
    std::cout << f<int>((int *)nullptr) << std::endl;
    return 0;
}
