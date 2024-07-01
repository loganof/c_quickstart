#include <vector>
#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int value) : val(value), next(nullptr) {}
};
#include <stack>

void printListReversely(ListNode *pHead)
{
    if (!pHead)
        return;
    // 辅助栈
    std::stack<ListNode *> nodes;
    ListNode *pReverseNode = pHead;
    while (pReverseNode != nullptr)
    {
        // nodes.emplace(pReverseNode);
        nodes.push(pReverseNode);
        pReverseNode = pReverseNode->next;
    }
    while (!nodes.empty())
    {
        pReverseNode = nodes.top();
        nodes.pop();
        printf("%d, ", pReverseNode->val);
    }
}

// 反转链表
#include <stack>
ListNode *reverseList(ListNode *pHead)
{
    if (pHead == nullptr)
        return pHead;
    ListNode *pPre = nullptr, *pCur = pHead, *pNext = nullptr;
    while (pCur->next != nullptr)
    {
        pNext = pCur->next;
        pCur->next = pPre;
        pPre = pCur;
        pCur = pNext;
    }
    pCur->next = pPre;
    return pCur;
}

// 两两反转链表
ListNode *reverseList2Nodes(ListNode *pHead)
{
    if (pHead == nullptr || pHead->next == nullptr || pHead->next->next == nullptr)
        return pHead;
    ListNode *pPre = nullptr, *pNode1 = pHead, *pNode2 = pHead->next, *pNext = nullptr;
    while (pNode2 != nullptr)
    {
        pNext = pNode2->next;
        pNode2->next = pPre;
        pPre = pNode1;
        pNode1 = pNext;
        if (pNode1 == nullptr)
            return pPre;
        pNode2 = pNext->next;
    }
    pNode1->next = pPre;
    return pNode1;
}

// 删除链表中的重复节点
// 由于头节点也可以删除，所以声明为2级指针
void delRepeatedNode(ListNode **pHead)
{
}

// 判断链表中是否有环，如果有环，返回环的入口节点
ListNode *meetingNode(ListNode *pHead)
{
    if (pHead == nullptr || pHead->next == nullptr)
        return nullptr;
    ListNode *slowNode = pHead;
    ListNode *fastNode = pHead->next;
    while (fastNode != nullptr && slowNode != nullptr)
    {
        if (fastNode == slowNode)
        {
            return fastNode;
        }
        fastNode = fastNode->next;
        slowNode = slowNode->next;
        if (fastNode != nullptr)
        {
            fastNode = fastNode->next;
        }
    }
    return nullptr;
}

// 计算环的入口节点
ListNode *entryNodeOfList(ListNode *pHead)
{
    if (pHead == nullptr)
        return nullptr;
    ListNode *pMeetingNode = meetingNode(pHead);
    if (pMeetingNode == nullptr)
    {
        return nullptr;
    }

    ListNode *pNode1 = pHead;
    ListNode *pNode2 = pMeetingNode->next;
    auto cycleNum = 1;
    // 得到环中数目
    while (pNode2 != pMeetingNode)
    {
        pNode2 = pNode2->next;
        cycleNum++;
    }
    printf("node num: %d\n", cycleNum);
    // 移动环中数
    while (cycleNum--)
    {
        pNode1 = pNode1->next;
    }
    pNode2 = pHead;
    while (pNode1 != pNode2)
    {
        pNode1 = pNode1->next;
        pNode2 = pNode2->next;
    }
    return pNode1;
}

ListNode *constructList(const std::vector<int> &vec)
{
    if (vec.size() <= 0)
        return nullptr;
    ListNode *pHead = new ListNode(vec[0]);
    ListNode *pTmp = pHead;
    for (int i = 1; i < vec.size(); i++)
    {
        pTmp->next = new ListNode(vec[i]);
        pTmp = pTmp->next;
    }

    return pHead;
}
ListNode *constuctLoopList(const std::vector<int> &vec)
{
    ListNode *pHead = constructList(vec);
    ListNode *pTmp = pHead;
    while (pTmp->next != nullptr)
    {
        pTmp = pTmp->next;
    }
    pHead->next->next = pTmp->next;
    return pHead;
}

auto print = [](ListNode *pHead)
{
    ListNode *tmp = pHead;
    while (tmp)
    {
        std::cout << tmp->val << "\n";
        tmp = tmp->next;
    }
};

ListNode *mergeList(ListNode *pHead1, ListNode *pHead2)
{
    if (pHead1 == nullptr)
        return pHead2;
    if (pHead2 == nullptr)
    {
        return pHead1;
    }

    ListNode *newHead = nullptr;
    if (pHead1->val < pHead2->val)
    {
        newHead = pHead1;
        pHead1 = pHead1->next;
    }
    else
    {
        newHead = pHead2;
        pHead2 = pHead2->next;
    }
    ListNode *tmpNode = newHead;
    while (pHead1 && pHead2)
    {
        if (pHead1->val < pHead2->val)
        {
            tmpNode->next = pHead1;
            pHead1 = pHead1->next;
        }
        else
        {
            tmpNode->next = pHead2;
            pHead2 = pHead2->next;
        }
        tmpNode = tmpNode->next;
    }
    if (pHead1)
    {
        tmpNode->next = pHead1;
    }
    if (pHead2)
        tmpNode->next = pHead2;
    return newHead;
}
// 迭代
ListNode *mergeList_v2(ListNode *pHead1, ListNode *pHead2)
{
}

int main(int argc, char const *argv[])
{
    std::vector<int> vec = {1, 3, 5, 7, 9, 11, 13};
    ListNode *pHead = constructList(vec);
    // 反向打印链表
    // printListReversely(pHead);
    // 反转链表
    // ListNode *newHead = reverseList(pHead);
    // 两两反转链表
    // ListNode *newHead = reverseList2Nodes(pHead);
    // print(newHead);
    // 构造循环链表
    // ListNode *pHead1 = constructList(vec);
    // ListNode *pRet = entryNodeOfList(pHead1);
    // if (pRet != nullptr)
    // {
    //     std::cout << "List has cycle, entry node val: " << pRet->val << "\n";
    // }
    // else
    // {
    //     std::cout << "List has no cycle.\n";
    // }
    std::vector<int> vec1 = {2, 4, 6, 8, 10};
    ListNode *pHead2 = constructList(vec1);
    ListNode *ret = mergeList(pHead, pHead2);
    print(ret);
    return 0;
}
