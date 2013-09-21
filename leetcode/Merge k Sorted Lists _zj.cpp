/*************************************************
Author:zhengjian
Date:2013-09-21
Description:Merge k Sorted Lists
Time:
Memory:
**************************************************/

#include<iostream>
#define N 10001
#include<vector>
#include<stack>
using namespace std;


/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"

这是个O(N*K)复杂度的解法，实在懒得写堆排了。。堆排能到O(N* log(K))
*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeKLists(vector<ListNode *> &lists) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    ListNode *result = NULL;
    ListNode *point;
    if(lists.size()==0) return result;
    if(lists.size() ==1) return lists[0];

    int max_int = (unsigned int)(-1) >>1;
    int tempMin = max_int;
    int temp;
    bool hasSomeThing= false;
    for(int i =0; i<lists.size(); i++) {
        if(lists[i]!=NULL&& lists[i]->val <tempMin) {
            hasSomeThing= true;
            tempMin = lists[i]->val;
            temp =i;
        }
    }
    if(!hasSomeThing) {
        return result;
    }
    result = new ListNode(tempMin);
    lists[temp] = lists[temp]->next;
    point = result;

    while(true) {
        tempMin = max_int;
        temp;
        hasSomeThing= false;
        for(int i =0; i<lists.size(); i++) {
            if(lists[i]!=NULL&& lists[i]->val <tempMin) {
                hasSomeThing= true;
                tempMin = lists[i]->val;
                temp =i;
            }
        }
        if(!hasSomeThing) break;
        point->next = lists[temp];
        point = point->next;
        lists[temp] = lists[temp]->next;
    }
    return result;
}

int main()
{
    ListNode * one = new ListNode(1);
    ListNode * tw = new ListNode(2);
    ListNode * three = new ListNode(3);
    ListNode * four = new ListNode(4);
    one->next = tw;
    tw->next = three;
    three->next = four;

    ListNode * one1 = new ListNode(3);
    ListNode * tw1 = new ListNode(4);
    ListNode * three1 = new ListNode(5);
    ListNode * four1 = new ListNode(6);
    one1->next = tw1;
    tw1->next = three1;
    three1->next = four1;

    vector< ListNode *> lists;


    ListNode * result = mergeKLists(lists);

    while(result!=NULL) {
        cout<<result->val<<endl;
        result = result->next;
    }

    return 0;
}


