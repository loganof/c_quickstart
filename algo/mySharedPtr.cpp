
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
