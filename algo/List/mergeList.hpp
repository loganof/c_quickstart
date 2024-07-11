#include "ListNode.hpp"

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