/*************************************************
Author:zhengjian
Date:2013-09-20
Description:Valid Parentheses
Time:
Memory:
**************************************************/

#include<iostream>
#define N 10001
#include<vector>
#include<stack>
using namespace std;


/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

char getq(char p) {

    if(p==')') {
        return '(';
    }
    else if(p=='}') {
        return '{';
    }
    else  if(p==']') {
        return '[';
    }
}

bool isValid(string s) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    stack<char> charstack ;
    int len = s.size();
    int point =0;
    while(point<len ) {
        if(s[point]=='('||s[point]=='{'||s[point]=='[') {
            charstack.push(s[point++]);
        } else if(s[point]==')'||s[point]=='}'||s[point]==']') {
            if(!charstack.empty()&&charstack.top()==getq(s[point])) {
                charstack.pop();
                point++;
            } else {
                return false;
            }
        }
    }
    if(charstack.empty()&& point==len) {
        return true;
    } else {
        return false;
    }
}
int main()
{


    cout<<isValid("[{}()][]{}");
    return 0;
}
