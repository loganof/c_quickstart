#include <string.h>
#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    char message[] = "Original message";
    // strcpy(message, "Different"); // 原始字符串部分丢失
    // strcpy(message, "A Different Message"); // 越界的风险
    // strcpy(message, "Hello");
    // strcat(message, ", how are you?");
    printf("message: %s\n", message);
    // 字符串查找
    char *ans = strchr(message, 's'); // 's'第一次出现的位置
    printf("ans: %s\n", ans);
    char *ret = strrchr(message, 's');
    printf("ret: %s\n", ret); // 's'最后出现的位置

    // char *ret1 = strpbrk(message, 'na');
    // printf("ret1: %s\n", ret1);

    // char *ret2 = strstr(message, 'na');
    // printf("ret2: %s\n", ret2);

    printf('bool result: %d\n', iscntrl('A'));
    return 0;
}
