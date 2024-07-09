// #include <vector>
// // 一个数组，找出重复次数最多的元素
// #define NULL_ARR -1
// int findMax(int *arr, int len)
// {
//     if (len <= 0)
//         return NULL_ARR;
//     if (len == 1)
//         return arr[0];
//     // 查找重复次数最多的数
//     // 先找出数组中最大的数N，创建N+1的辅助空间arr1[N+1]
//     // 遍历原数组，数字i出现时，在arr1[i]++，然后找出arr1[i]中最大的数
//     // 如果中间有负数，该方法不行,先考虑正数
//     int max = findMaxInArray(arr, len);
//     int arr1[max];
//     // 用辅助数组进行统计
//     for (int i = 0; i < len; i++)
//     {
//         arr1[arr[i]]++;
//     }
//     // 找出辅助数组最大的数
//     int item = findMaxInArray(arr1, max);
//     return arr1[item];
// }

// int findMaxInArray(int *arr, int len)
// {
//     int max = 0;
//     for (int i = 0; i < len; i++)
//     {
//         if (arr[i] >= max)
//         {
//             max = arr[i];
//         }
//     }
//     return max;
// }

#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
    string str = "a,1,b,2,c,3";
    istringstream instream(str);

    // instream.setf(",");
    string s;
    while (getline(instream, s, ','))
    {
        cout << s << endl;
    }
    std::vector<int> vec;
    vec.push_back(1);
    return 0;
}

// stl容器
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>

std::vector<int> a;
std::stack<int> stk;
std::queue<int> que;
std::priority_queue<int> pri_deq;
std::deque<int> deq;
std::list<int> list;
a.back();
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

std::set<int> mySet;
std::multiset<int> mulset;
std::unordered_set<int> unorderset;
std::unordered_multiset<int> unmultiset;
std::map<int, int> mp;
std::multimap<int, int> multimp;
std::unordered_map<int, int> unmap;
std::unordered_multimap<int, int> un_mutimp;
