#include <stdio.h>

int ExlusiveOR(int arr[], int len)
{
    int result = 0;
    for (int i = 0; i < len; i++)
    {
        result ^= arr[i];
    }
    return result;
}

unsigned int FindFirstBitIs1(int resultOfExclusiveOR)
{
    int indexBit = 0;
    while (((resultOfExclusiveOR & 1) == 0) && (indexBit < 8 * sizeof(int)))
    {
        resultOfExclusiveOR = resultOfExclusiveOR >> 1;
        ++indexBit;
    }
    return indexBit;
}

bool IsBit1(int num, unsigned indexBit)
{
    num = num >> indexBit;
    return (num & 1);
}

void Find2NumsAppearOnce(int *arr, int len, int *num1, int *num2)
{
    int exlusiveOR = ExlusiveOR(arr, len);
    printf("exlusiveOR: %d\n", exlusiveOR);

    unsigned int indexBit = FindFirstBitIs1(exlusiveOR);
    printf("indexBit: %d\n", indexBit);

    for (size_t i = 0; i < len; ++i)
    {
        if (IsBit1(arr[i], indexBit))
        {
            *num1 ^= arr[i];
        }
        else
        {
            *num2 ^= arr[i];
        }
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {2, 4, 3, 6, 3, 2, 5, 5};
    int len = sizeof(arr) / sizeof(int);
    printf("len: %d\n", len);

    int num1 = 0, num2 = 0;
    Find2NumsAppearOnce(arr, len, &num1, &num2);
    printf("num1: %d, num2: %d \n", num1, num2);

    return 0;
}
