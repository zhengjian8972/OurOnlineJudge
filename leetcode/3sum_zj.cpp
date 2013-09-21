/*************************************************
Author:zhengjian
Date:2013-09-16
Description:3 sum
Time:
Memory:
**************************************************/

#include<iostream>
#define N 10001
#include<vector>
using namespace std;

/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?

Find all unique triplets in the array which gives the sum of zero.

这是个 O(N^2)的解法
*/


vector<vector<int> > threeSum(vector<int> &num) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<vector<int> > result;
    if(num.size()<3) return result;
    sort(num.begin(),num.end());
    int len = num.size();
    int before;
    int after;
    int tempsum;
    int lastV = num[0]-1;

    for(int i =0; i< len && num[i]<=0; i++) {
        if (num[i] == lastV) continue;
        lastV = num[i];
        before = i+1;
        after = len-1;

        while(before<after) {
            tempsum = num[before] +num[after] + num[i];
            if(tempsum==0) {
                vector<int> *temp = new vector<int>(3);
                vector<int> & ptemp = *temp;
                ptemp[0]=num[i];
                ptemp[1]=num[before];
                ptemp[2]=num[after];
                result.push_back(ptemp);
                before++;
            }
            else if(tempsum<0) {
                before++;
            } else if(tempsum>0) {
                after--;
            }
        }
    }
    sort(result.begin(),result.end());
    result.erase(unique(result.begin(),result.end()),result.end());
    return result;
}

int main()
{
    vector<int> input;
    input.push_back(-1);
    input.push_back(-1);
    input.push_back(1);
    input.push_back(0);

    vector<vector<int> > result = threeSum(input);
    for(int i =0; i<result.size(); i++) {
        vector<int> temp = result[i];
        for(int j =0; j<temp.size(); j++)
            cout<<temp[j]<<" ";
        cout<<endl;
    }
    return 0;
}
