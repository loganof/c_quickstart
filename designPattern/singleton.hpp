#include <iostream>
class SingleTon
{
private:
    SingleTon() {}

public:
    static SingleTon &getInstance()
    {
        static SingleTon ins;
        return ins;
    }
    ~SingleTon() {}
    void act()
    {
        std::cout << "hello" << std::endl;
    }
};