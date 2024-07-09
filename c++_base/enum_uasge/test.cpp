#include <stdio.h>

enum Color
{
    RED,
    GREEN,
    BLUE
};

int main(int argc, char const *argv[])
{
    enum Color myColor;
    myColor = RED;
    printf("myColor: %d \n", myColor);
    return 0;
}
