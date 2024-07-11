

// 3.1 找出数组中重复的数字(数组辅助)
int repeatNumber(int *arr, int n)
{
    int *temp = new int[n];
    for (int i = 0; i < n; i++)
    {
        temp[arr[i]]++;
        if (temp[arr[i]] >= 2)
            return arr[i];
    }
}

//  找出数组中重复的数字(无辅助数组)
// 比较巧妙，后面再写

// 3.2 不修改数组找出重复的数字(数组辅助)

// 4.1 二维数组中的查找
// 5.1 替换空格
