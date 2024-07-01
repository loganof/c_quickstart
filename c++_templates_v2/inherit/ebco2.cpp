#include <iostream>

class Empty
{
    using Int = int;
};

class EmptyToo : public Empty
{
};

class EmptyThree : public Empty, public EmptyToo
{
};

int main(int argc, char const *argv[])
{
    std::cout << "sizeof(Empty): " << sizeof(Empty) << '\n';
    std::cout << "sizeof(EmptyToo): " << sizeof(EmptyToo) << '\n';
    std::cout << "sizeof(EmptyThree): " << sizeof(EmptyThree) << '\n';
    return 0;
}
