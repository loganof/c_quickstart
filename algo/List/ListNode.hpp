#ifndef LISTNODE_H_P_P
#define LISTNODE_H_P_P
#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int value) : val(value), next(nullptr) {}
};

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

auto printList = [](ListNode *pHead)
{
    ListNode *tmp = pHead;
    while (tmp)
    {
        std::cout << tmp->val << "\n";
        tmp = tmp->next;
    }
};

#endif // LISTNODE_H_P_P