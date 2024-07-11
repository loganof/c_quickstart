/*
<string.h> 提供了用于操作C风格字符串的函数。
1. strlen
2. strcpy/strncpy
3. strcat/strncat
4. strcmp/strncmp
5. memcpy
6. memset
*/

#include <string.h>

int main(int argc, char const *argv[])
{
    char * str1 = "hello logan";
    char str2 = malloc(strlen(str1) + 1);
    strlen(str1);
    
    return 0;
}
