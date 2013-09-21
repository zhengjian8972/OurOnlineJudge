/*************************************************
Author:zhengjian
Date:2013-08-25
Description:LongestCommonPrefix
Time:
Memory:
**************************************************/

#include<iostream>
#define N 10001
#include<vector>
using namespace std;

/*
Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.
*/

string longestCommonPrefix(vector<string> &strs) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if(strs.size()==0)
        return "";
    int befor =0;
    int len = strs[0].size();
    for(int i =1; i< strs.size(); i++) {
        int len2=0;
        while(len2<=len) {
            if(strs[i][len2]!= strs[befor][len2]) {
                break;
            }
            len2++;
        }
        if(len2< len) {
            len = len2;
            befor = i;
        }
    }
    return strs[0].substr(0,len);
}

int main()
{
    vector<string> arr ;
    arr.push_back("a");
    arr.push_back("eabcde");
    arr.push_back("abcee");
    arr.push_back("abcdc");
    cout<< longestCommonPrefix(arr);
    return 0;
}
