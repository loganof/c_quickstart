#include "ListNode.hpp"

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
