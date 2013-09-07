#include<iostream>
#define N 10001
#include<string.h>
using namespace std;
/*
Implement regular expression matching with support for '.' and '*'.
'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).
The function prototype should be:
bool isMatch(const char *s, const char *p)
Some examples:
isMatch("aa","a") ? false
isMatch("aa","aa") ? true
isMatch("aaa","aa") ? false
isMatch("aa", "a*") ? true
isMatch("aa", ".*") ? true
isMatch("ab", ".*") ? true
isMatch("aab", "c*a*b") ? true

用递归方法妥妥的
*/

bool isMatch(const char *s, const char *p)
{
    if(s==NULL|| p==NULL ) return false;
    if(*p=='\0') return (*s=='\0');

    if(*(p+1)=='*'){
        while( (*s!='\0'&&*p=='.')|| *s==*p){
            if( isMatch(s,p+2)) return true;
            s++;
        }
        return isMatch(s,p+2);
    }else{
        if((*s!='\0'&& *p=='.')|| *s ==*p){
            return isMatch(s+1,p+1);
        }
        return false;
    }
}

int main()
{

    char s[4]= {'a','a','b'};
    s[3] = '\0';

    char p[3]= {'c','*'};
    p[2] = '\0';
    if(isMatch(s,p))
        cout<<"isMatch(s,p)"<<endl;
    else
        cout<<"no";
    return 0;
}
