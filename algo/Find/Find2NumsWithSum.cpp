#include <stdio.h>

bool Find2NumsWithSum(int *arr, int len, int sum, int *num1, int *num2)
{
    int firstPtr = 0;
    int lastPtr = len - 1;
    int sum2Nums = 0;
    while (firstPtr < lastPtr)
    {
        sum2Nums = arr[firstPtr] + arr[lastPtr];
        if (sum2Nums == sum)
            break;
        else if (sum2Nums > sum)
        {
            lastPtr--;
        }
        else
        {
            firstPtr++;
        }
    }
    if (firstPtr < lastPtr)
    {
        *num1 = arr[firstPtr];
        *num2 = arr[lastPtr];
        return true;
    }
    return false;
}
int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 4, 7, 11, 15};
    int sum = 15;
    int len = sizeof(arr) / sizeof(int);
    int num1 = 0, num2 = 0;

    if (Find2NumsWithSum(arr, len, sum, &num1, &num2))
    {
        printf("num1: %d, num2: %d \n", num1, num2);
    }
    else
    {
        printf("can't find appropriate numbers.\n");
    }
}
