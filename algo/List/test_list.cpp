#include <vector>
#include "reverseList.hpp"
#include "reverseList2Nodes.hpp"
#include "printListReverse.hpp"
#include "mergeList.hpp"
#include "entryNodeOfList.hpp"

int main(int argc, char const *argv[])
{
    // construct test lists
    std::vector<int> vec = {1, 3, 5, 7, 9, 11, 13};
    ListNode *pHead = constructList(vec);

    std::vector<int> vec1 = {2, 4, 6, 8, 10};
    ListNode *pHead2 = constructList(vec1);

    ListNode *pHead3 = constuctLoopList(vec);

    // print list reversely
    printListReversely(pHead);

    // reverse list
    ListNode *newHead = reverseList(pHead);

    // reverse list by 2 nodes
    newHead = reverseList2Nodes(pHead);

    newHead = mergeList(pHead, pHead2);

    ListNode *pRet = entryNodeOfList(pHead);
    if (pRet != nullptr)
    {
        std::cout << "List has cycle, entry node val: " << pRet->val << "\n";
    }
    else
    {
        std::cout << "List has no cycle.\n";
    }

    printList(newHead);
    return 0;
}