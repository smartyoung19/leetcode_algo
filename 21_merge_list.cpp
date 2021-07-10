/*
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

两个链表的节点数目范围是 [0, 50]
-100 <= Node.val <= 100
l1 和 l2 均按 非递减顺序 排列

*/

#include "common_def.h"

using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        // get head node
        ListNode *pHead = new ListNode(0);  // temp data
        ListNode *pNow = pHead;
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val <= list2->val)
            {
                // connect list1
                pNow->next = list1;
                // go to next
                list1 = list1->next;
            }
            else
            {
                // connect list2
                pNow->next = list2;
                // go to next
                list2 = list2->next;
            }
            pNow = pNow->next;
        }
        
        // deal the left data
        if (nullptr == list1)
        {
            pNow->next = list2;
        }
        if (nullptr == list2)
        {
            pNow->next = list1;
        }

        ListNode *pRes = pHead->next;
        delete pHead;
        return pRes;
    }
};


int main()
{
    int d1[4] = {-1, 2, 4, 9};
    int d2[4] = {0, 1, 3, 4};
    ListNode* p1 = CreateListNode(d1, 4);
    ListNode* p2 = CreateListNode(d2, 4);
    Solution slu;
    ListNode* p3 = slu.mergeTwoLists(p1, p2);
    PrintListNode(p3);

    FreeListNode(p3); // p3 has all memory of p1 and p2 node.
    system("pause");
    return 0;
}