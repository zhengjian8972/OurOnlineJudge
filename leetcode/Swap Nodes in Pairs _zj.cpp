/*************************************************
Author:zhengjian
Date:2013-09-22
Description:Swap Nodes in Pairs
Time:
Memory:
**************************************************/

#include<iostream>
#define N 10001
#include<vector>
#include<stack>
using namespace std;


/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *swapPairs(ListNode *head) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if(head == NULL) return NULL;
    if(head->next==NULL) return head;
    ListNode * first = head;
    ListNode * second = head->next;
    ListNode * nextHead= second->next;
    second->next = first;
    first->next = swapPairs(nextHead);
    return second;
}

int main()
{
    ListNode* one = new ListNode(1);
    ListNode* two = new ListNode(2);
    ListNode* three = new ListNode(3);
    ListNode* four = new ListNode(4);

    one->next = two;
    two->next = three;
    three->next = four;

    ListNode * result = swapPairs(one);
    while(result!=NULL) {
        cout<<result->val<<" ";
        result = result->next;
    }
    cout<<endl;
    return 0;
}












