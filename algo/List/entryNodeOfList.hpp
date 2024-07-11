#include "ListNode.hpp"

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
