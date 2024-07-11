/*
<ctype.h> 提供了用于分类和转换字符的函数
1. isalnum:检查是否是字母或数字
*/

#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    char str[] = "hello";
    printf("result: %d\n", isalnum(str));
    char str1 = 'A';
    printf("result: %d\n", isdigit(3));

    return 0;
}
