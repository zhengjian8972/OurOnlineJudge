/*************************************************
Author:zhengjian
Date:2013-09-22
Description:Reverse Nodes in k-Group
Time:
Memory:
**************************************************/

#include<iostream>
#define N 10001
#include<vector>
#include<stack>
using namespace std;


/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseKGroup(ListNode *head,int k) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if(k ==1) return head;

    int round = k ;
    ListNode * nextPointer = head;
    while(round>0) {
        if(nextPointer == NULL) {
            return head;
        }
        else {
            nextPointer = nextPointer->next;
            round--;
        }
    }

    if(k ==2 ) {
        ListNode  * currentHead = head;
        ListNode * nextNode = currentHead->next;
        currentHead->next= reverseKGroup(nextPointer,k);
        nextNode->next= currentHead;
        return nextNode;
    }
    else {
        ListNode   * currentHead = head;
        ListNode * nextNode = currentHead->next;
        ListNode * nextNextNode = nextNode->next;

        currentHead->next= reverseKGroup(nextPointer,k);

        while(nextNode != nextPointer) {
            nextNode->next = currentHead;
            currentHead = nextNode;
            nextNode = nextNextNode;
            if(nextNode !=NULL) {
                nextNextNode = nextNode->next;
            }
        }
        return currentHead;
    }
}

int main()
{
    ListNode* one = new ListNode(1);
    ListNode* two = new ListNode(2);
    ListNode* three = new ListNode(3);
    ListNode* four = new ListNode(4);
    ListNode* five = new ListNode(5);
    ListNode* six = new ListNode(6);

    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = six;


    ListNode * result = reverseKGroup(one,3);
    while(result!=NULL) {
        cout<<result->val<<" ";
        result = result->next;
    }
    cout<<endl;
    return 0;
}












