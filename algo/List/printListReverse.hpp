#include "ListNode.hpp"
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