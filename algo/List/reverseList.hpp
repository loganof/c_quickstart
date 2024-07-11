#include "ListNode.hpp"

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

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param head ListNode类
     * @return ListNode类
     */
    ListNode *ReverseList(ListNode *head)
    {
        // write code here
        if (!head || !head->next)
        {
            return head;
        }
        // 使用栈
        // stack<int> stk;
        // ListNode* tmpNode = head;
        // while (tmpNode) {
        //     stk.push(tmpNode->val);
        //     tmpNode = tmpNode->next;
        // }
        // ListNode* newHead = new ListNode(stk.top());
        // tmpNode = newHead;
        // stk.pop();
        // while(!stk.empty()){
        //     tmpNode->next = new ListNode(stk.top());
        //     tmpNode = tmpNode->next;
        //     stk.pop();
        // }
        // return newHead;
        // 使用2个指针
        ListNode *last = nullptr;
        ListNode *cur = head;
        ListNode *next = nullptr;

        while (cur->next)
        {
            next = cur->next;
            cur->next = last;
            last = cur;
            cur = next;
        }
        cur->next = last;
        return cur;
    }
};
