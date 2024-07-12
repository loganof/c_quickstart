#include <iostream>

void bigLittleEndian()
{
    int a = 0x123456;
    char ch = char(a);
    if (ch == 0x01)
    {
        std::cout << "big endian.\n";
    }
    else if (ch == 0x56)
    {
        std::cout << "little endian.\n";
    }
    else
    {
        std::cout << "unknow endian.\n";
    }
}