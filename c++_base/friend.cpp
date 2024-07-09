#include <iostream>

class Box
{
private:
    double width;

public:
    friend void printWidth(Box box);
    void setWidth(double wid);
};

void Box::setWidth(double wid)
{
    width = wid;
}

void printWidth(Box box)
{
    std::cout << "Width of box: " << box.width << std::endl;
}

int main(int argc, char const *argv[])
{
    Box box;
    box.setWidth(10.0);
    printWidth(box);
    return 0;
}
