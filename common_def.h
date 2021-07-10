#ifndef _COMMON_DEF_H_
#define _COMMON_DEF_H_

#include <iostream>

using std::cout;
using std::endl;


struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void PrintListNode(ListNode * p_head)
{
    if (p_head == nullptr)
    {
        cout << "Empty ListNode" << endl;
        return;
    }

    ListNode* p_now = p_head;
    while (p_now != nullptr)
    {
        cout << p_now->val << " -> ";
        p_now = p_now->next;
    }
    cout << endl;
}



ListNode* CreateListNode(int * data, int len)
{
    ListNode* p_head = nullptr;
    ListNode* p_now = nullptr;
    if (len < 1) return p_head;

    p_head = new ListNode(data[0]);
    p_now = p_head;

    for (int i = 1; i < len; ++i)
    {
        p_now->next = new ListNode(data[i]);
        p_now = p_now->next;
    }

    cout << "ListNode created: ";
    PrintListNode(p_head);
    return p_head;
}


void FreeListNode(ListNode * p_head)
{
    if (p_head == nullptr)
    {
        cout << "Empty ListNode" << endl;
        return;
    }

    ListNode* p_now = p_head;
    ListNode* p_next = nullptr;
    while (p_now != nullptr)
    {
        p_next = p_now->next;
        delete p_now;
        p_now = p_next;
    }
    p_head = nullptr;
}

#endif