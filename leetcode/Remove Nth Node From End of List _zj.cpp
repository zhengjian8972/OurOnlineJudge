/*************************************************
Author:zhengjian
Date:2013-09-20
Description:Remove Nth Node From End of List
Time:
Memory:
**************************************************/

#include<iostream>
#define N 10001
#include<vector>
using namespace std;

/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int step = n;
    ListNode * before = head;
    ListNode * after = head;

    while(step >= 0) {
        if(!before) {
            return head->next;
        }
        before = before->next;
        step--;
    }
    while(before) {
        before = before->next;
        after = after->next;
    }
    ListNode *deleted = after->next;
    after->next = deleted->next;
    return head;
}

int main()
{
    ListNode *one = new ListNode(1);
    ListNode *two = new ListNode(2);
    ListNode *three = new ListNode(3);
    ListNode *four = new ListNode(4);
    one->next = two;
    two->next=three;
    three->next =four;

    ListNode *now = removeNthFromEnd(one,4);
    while(now) {
        cout<< now->val<<" ";
        now = now->next;
    }

    cout<<endl;
    return 0;
}
