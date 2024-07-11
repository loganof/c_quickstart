
#if 1

// 递归实现

// 9.1 用两个栈实现队列

// 10.1 斐波那契数列
// 10.2 青蛙跳台阶

// 11.1 旋转数组的最小数字
// 12.1 矩阵中的路径
// 13.1 机器人的运动范围
// 14.1 剪绳子
// 15.1 二进制中1的个数
// 16.1 数值的整数次方
// 17.1 打印从1到最大的n位数
// 18.1 删除链表中的节点
// 18.2 删除链表中的重复节点
// 19.1 正则表达式的匹配
// 20.1 表示数值的字符串
// 21 调整数组的顺序使奇数位于偶数前面
// 22.1 链表中倒数的第K个节点
// 23 链表中环的入口节点
// 24.1 反转链表
// 24.2 每隔n个节点反转链表
// 25 合并2个排序链表
// 26 判断树的子结构
//

#include <cstdio>

#endif

#if 1
void bubbleSort(std::vector<int> &arr)
{
    int len = arr.size();
    for (int i = 0; i < len; ++i)
    {
        for (int j = 1; j < len; ++j)
        {
            if (arr[j] < arr[j - 1])
            {
                std::swap(arr[i], arr[j]);
            }
        }
    }
}

void insertSort(std::vector<int> &arr)
{
    int len = arr.size();
    for (int i = 1; i < len; ++i)
    {
        for (int j = i; j > 0; --j)
        {
            if (arr[j] < arr[j - 1])
            {
                std::swap(arr[j], arr[j - 1]);
            }
            else
            {
                break;
            }
        }
    }
}

void selectSort(std::vector<int> &arr)
{
    int len = arr.size();
    for (int i = 0; i < len; ++i)
    {
        int min = i;
        for (int j = i + 1; j < len; ++j)
        {
            if (arr[min] > arr[j])
                min = j;
        }
        std::swap(arr[i], arr[min]);
    }
}
// 还需要花时间理解
void shellSort(std::vector<int> &arr)
{
    int len = arr.size();
    for (int gap = len / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < len; ++i)
        {
            for (int j = i; j >= gap; j -= gap)
            {
                if (arr[j] < arr[j - gap])
                    std::swap(arr[j], arr[j - gap]);
                else
                    break;
            }
        }
    }
}
void quickSort_impl(std::vector<int> &arr, int left, int right);
void quickSort(std::vector<int> &arr)
{
    int len = arr.size();
    quickSort_impl(arr, 0, len - 1);
}
void quickSort_impl(std::vector<int> &arr, int left, int right)
{
    if (left > right)
    {
        return;
    }
    int i = left, j = right;
    int base = arr[left];
    while (i < j)
    {
        while (i < j && arr[j] >= base)
            --j;
        while (i < j && arr[i] <= base)
            ++i;
        if (i < j)
            std::swap(arr[i], arr[j]);
    }
    std::swap(arr[left], arr[i]);
    quickSort_impl(arr, left, i - 1);
    quickSort_impl(arr, i + 1, right);
}

void adjustHeap(std::vector<int> &, int, int);

void heapSort(std::vector<int> &arr)
{
    int len = arr.size();
    // 构造大顶堆
    for (int i = len / 2 - 1; i >= 0; --i)
    {
        adjustHeap(arr, len, i);
    }
    for (int i = len - 1; i >= 0; --i)
    {
        std::swap(arr[0], arr[i]);
        adjustHeap(arr, i, 0);
    }
}

void adjustHeap(std::vector<int> &arr, int len, int node)
{
    if (len <= 0)
        return;
    int left = node * 2 + 1;
    int right = node * 2 + 2;
    int max = node;
    if (left < len && arr[max] < arr[left])
        max = left;
    if (right < len && arr[max] < arr[right])
        max = right;
    if (max != node)
    {
        std::swap(arr[max], arr[node]);
        adjustHeap(arr, len, max);
    }
}
void merge(std::vector<int> &arr, int left, int gap, int right);
void mergeSort_impl(std::vector<int> &arr, int left, int right);

void mergeSort(std::vector<int> &arr)
{
    int len = arr.size();
    mergeSort_impl(arr, 0, len - 1);
}

void mergeSort_impl(std::vector<int> &arr, int left, int right)
{
    if (left >= right)
        return;
    int gap = left + (right - left) / 2;
    mergeSort_impl(arr, left, gap);
    mergeSort_impl(arr, gap + 1, right);
    merge(arr, left, gap, right);
}
int count = 0;
void merge(std::vector<int> &arr, int left, int gap, int right)
{
    if (left >= right)
        return;
    int len = right - left + 1;
    int i = left, j = gap + 1;
    std::vector<int> tmp(len, 0);
    int index = 0;
    while (i <= gap && j <= right)
    {
        // tmp[index++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
        if (arr[i] < arr[j])
            tmp[index++] = arr[i++];
        else
        {
            tmp[index++] = arr[j++];
            count += gap - i + 1;
        }
    }
    while (i <= gap)
        tmp[index++] = arr[i++];
    while (j <= right)
        tmp[index++] = arr[j++];
    for (int i = left; i <= right; ++i)
    {
        arr[i] = tmp[i - left];
    }
}

int main(int argc, char const *argv[])
{
    // SingleTon::getInstance().act();
    // return 0;

    std::vector<int> arr = {2,
                            3,
                            2,
                            -1,
                            8,
                            13,
                            -2};
    std::vector<int> arr3 = {364, 637, 341, 406, 747, 995, 234, 971, 571, 219, 993, 407, 416, 366, 315, 301, 601, 650, 418, 355, 460, 505, 360, 965, 516, 648, 727, 667, 465, 849, 455, 181, 486, 149, 588, 233, 144, 174, 557, 67, 746, 550, 474, 162, 268, 142, 463, 221, 882, 576, 604, 739, 288, 569, 256, 936, 275, 401, 497, 82, 935, 983, 583, 523, 697, 478, 147, 795, 380, 973, 958, 115, 773, 870, 259, 655, 446, 863, 735, 784, 3, 671, 433, 630, 425, 930, 64, 266, 235, 187, 284, 665, 874, 80, 45, 848, 38, 811, 267, 575};
    // std::vector<int> arr1(50, 1);
    // arr1[49] = 40;
    // bubbleSort(arr);
    // insertSort(arr);
    // selectSort(arr);
    // shellSort(arr);
    // quickSort(arr);
    // heapSort(arr);

    mergeSort(arr3);
    std::cout << "count: " << count << std::endl;
    auto print = [](std::vector<int> &vec)
    {
        for (auto &&i : vec)
        {
            std::cout << i << std::endl;
        }
    };
    print(arr);
    std::cout << int('A');
    return 0;
}
#endif

// 大小端判断
void bigLittleEndian()
{
    int a = 0x123456;
    char ch = char(a);
    if (ch == 0x01)
    {
        std::cout << "big endian.\n";
    }
    else if (ch == 0x56)
    {
        std::cout << "little endian.\n";
    }
    else
    {
        std::cout << "unknow endian.\n";
    }
}

// 手写智能指针
template <typename T>
class mySharedPtr
{
private:
    T *ptr;
    T *pCount;

public:
    // 默认构造
    mySharedPtr() : ptr(nullptr), pCount(new int(1)) {}
    // 拷贝构造
    mySharedPtr(mySharedPtr<T> &other)
    {
        ptr = other.ptr;
        pCount = other.pCount;
        (*pCount)++;
    }
    // 赋值操作
    mySharedPtr<T> &operator=(mySharedPtr<T> &other)
    {
        if (this == other)
            return this;
        ptr = other.ptr;
        pCount = other.pCount;
        (*pCount)++;
        return this;
    }
    ~mySharedPtr()
    {
        (*pCount)--;
        if ((*pCount) == 0)
        {
            delete ptr;
            ptr = nullptr;
            delete pCount;
            pCount == nullptr;
        }
    }
};

// 手写线程池
// 手写内存池
