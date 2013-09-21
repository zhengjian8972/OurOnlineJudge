/*************************************************
Author:zhengjian
Date:2013-09-16
Description:4 sum
Time:
Memory:
**************************************************/

#include<iostream>
#define N 10001
#include<vector>
using namespace std;

/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target?
Find all unique quadruplets in the array which gives the sum of target.

这是个 O(N^3)的解法
*/


vector<vector<int> > threeSum(vector<int> &num, int target) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<vector<int> > result;
    if(num.size()<4) return result;
    sort(num.begin(),num.end());
    int len = num.size();
    int before;
    int after;
    int tempsum;
    int lastV = num[0]-1;

    for(int i =0; i< len-3 ; i++) {
        if (num[i] == lastV) continue;
        lastV = num[i];
        for(int j =i+1; j< len-2; j++) {

            before = j+1;
            after = len-1;
            while(before<after) {
                tempsum = num[before] +num[after] + num[i] +num[j];
                if(tempsum==target) {
                    vector<int> *temp = new vector<int>(4);
                    vector<int> & ptemp = *temp;
                    ptemp[0]=num[i];
                    ptemp[1]=num[j];
                    ptemp[2]=num[before];
                    ptemp[3]=num[after];
                    result.push_back(ptemp);
                    before++;
                }
                else if(tempsum<target) {
                    before++;
                } else if(tempsum>target) {
                    after--;
                }
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
    input.push_back(1);
    input.push_back(-2);
    input.push_back(-4);
    input.push_back(-5);
    input.push_back(-3);
        input.push_back(3);
        input.push_back(3);
    input.push_back(5);

    vector<vector<int> > result = threeSum(input,-11);
    for(int i =0; i<result.size(); i++) {
        vector<int> temp = result[i];
        for(int j =0; j<temp.size(); j++)
            cout<<temp[j]<<" ";
        cout<<endl;
    }
    return 0;
}
