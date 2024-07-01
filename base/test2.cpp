#include <iostream>

class A
{
public:
    explicit A(int x)
    {
        std::cout << "call A(int x)" << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    // A a = 1; // 输出：call A(int x)
    char *pChar = "hello";
    char arr[10] = "";
    printf("len1: %d\n", sizeof(pChar));
    printf("len2: %d\n", strlen(pChar));
    printf("len3: %d\n", strlen(arr));
    printf("len4: %d\n", sizeof(arr));
    memcpy(arr, pChar, strlen(pChar));
    memset(arr, 'c', sizeof(arr));
    printf("arr: %s\n", arr);
    return 0;
}
