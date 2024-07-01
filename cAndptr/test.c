#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int matrix[6][10];
    int *mp;
    mp = &matrix[3][8];
    printf("First value is %d\n", *mp);
    printf("Second value is %d\n", *++mp);
    printf("Third value is %d\n", *++mp);
    char *str = "hello";
    printf("strlen: %lu\n", strlen(str));
    printf(",result: %d\n", (1, 2, 3));

    return 0;
}
