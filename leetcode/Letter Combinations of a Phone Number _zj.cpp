/*************************************************
Author:zhengjian
Date:2013-09-20
Description:Letter Combinations of a Phone Number
Time:
Memory:
**************************************************/

#include<iostream>
#define N 10001
#include<vector>
using namespace std;

/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

*/


string numbers [10]= {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
vector<string> letterCombinations(string digits) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<string> result;
    if(digits.size()<1) {
        result.push_back("");
        return result;
    }

    int realnum = digits[0]-'0';
    if(digits.size()==1) {
        for(int i = 0; i < numbers[realnum].size(); i++) {
            result.push_back( numbers[realnum].substr(i,1));
        }
        return result;
    }
    else {
        int firstnum = digits[0]-'0';
        vector<string> subresult = letterCombinations( digits.substr(1,digits.size()-1));
        for(int i =0; i< numbers[realnum].size(); i++) {
            for(int j =0; j < subresult.size(); j++) {
                result.push_back( numbers[realnum].substr(i,1)+ subresult[j] );
            }
        }
        return result;
    }
}

int main()
{
    vector<string> result;
    result=   letterCombinations("23");
    for(int i =0; i<result.size(); i++) {
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}
