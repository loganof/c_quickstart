#include <stdint.h>
#include <iostream>
#include <stddef.h>
#include <stdalign.h>

struct Info
{
    uint8_t a;
    uint16_t b;
    uint8_t c;
};
struct alignas(4) Info2
{
    uint8_t a;
    uint32_t b;
    uint8_t c;
};

struct Foo
{
    Foo() { std::cout << this << std::endl; }
    char a;
    char b;
    int c;
    char d;
};

int main(int argc, char const *argv[])
{
    // std::cout << sizeof(Info) << std::endl;
    // std::cout << alignof(Info) << std::endl;
    // std::cout << offsetof(Info, a) << '\n'
    //           << offsetof(Info, b) << '\n'
    //           << offsetof(Info, c) << '\n';
    std::cout << sizeof(Info2) << std::endl;
    std::cout << alignof(Info2) << std::endl;
    std::cout << offsetof(Info2, a) << '\n'
              << offsetof(Info2, b) << '\n'
              << offsetof(Info2, c) << '\n';
    // std::cout << sizeof(Foo) << std::endl;
    // std::cout << alignof(Foo) << std::endl;
    // std::cout << offsetof(Foo, a) << '\n'
    //           << offsetof(Foo, b) << '\n'
    //           << offsetof(Foo, c) << '\n'
    //           << offsetof(Foo, d) << '\n';
    return 0;
}
