/*************************************************
Author:zhengjian
Date:2013-09-21
Description:Generate Parentheses
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
*/


vector<string> generateParenthesis(int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<string> result;
    if(n ==1 ) {
        result.push_back("()");
        return result;
    }
    else {
        int nn = n/2;
        while(nn>1) {
            vector<string> subresult1 = generateParenthesis(n-nn);
            vector<string> subresult2 = generateParenthesis(nn);

            for(int i =0; i< subresult1.size(); i++) {
                for(int j =0; j < subresult2.size(); j++) {
                    result.push_back( subresult1[i]+ subresult2[j]);
                    result.push_back( subresult2[j]+ subresult1[i]);
                }
            }
            nn--;
        }
        vector<string> subresult = generateParenthesis(n-1);
        for(int i = 0; i< subresult.size(); i++) {
            result.push_back("()"+subresult[i]);
            result.push_back(subresult[i]+"()");
            result.push_back("("+subresult[i]+")");
        }

        sort(result.begin(),result.end());
        result.erase(unique(result.begin(),result.end()),result.end());
        return result;
    }
}

int main()
{
    vector<string> result = generateParenthesis(5);
    for(int i =0; i<result.size(); i++) {
        cout<<result[i]<<endl;
    }
    return 0;
}


