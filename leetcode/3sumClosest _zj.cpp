/*************************************************
Author:zhengjian
Date:2013-09-16
Description:3Sum Closest
Time:
Memory:
**************************************************/

#include<iostream>
#define N 10001
#include<vector>
using namespace std;

/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
Return the sum of the three integers.
You may assume that each input would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

细节写的不好，肯定还能再优化的
*/


    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int MAX_INT = (unsigned int)(-1)>>1;
        int closest = (int)MAX_INT;
        int closestsum ;
        int len = num.size();
        int tempClosest;
        int before;
        int after;
        int gap;
        int absgap;
        int sum;
        sort(num.begin(),num.end());
        for(int i =0;i<len-2;i++){
            tempClosest = MAX_INT;
            before = i+1;
            after = len-1;
            while(before<after){
                gap = num[i]+num[before]+ num[after]- target;
                absgap = abs(gap);
                if(absgap < tempClosest){
                    tempClosest= absgap;
                    sum = num[i]+num[before]+ num[after];
                }
                if(gap <0){
                    before ++;
                }
                else if(gap >0){
                    after --;
                }else if(gap==0){return target;}
            }

            if(tempClosest < closest){
                closest = tempClosest;
                closestsum = sum;
            }
        }
        return closestsum;
    }
int main()
{
    vector<int> input;
    input.push_back(1);
    input.push_back(1);
    input.push_back(1);
    input.push_back(0);

    cout<<threeSumClosest(input,-100);
    return 0;
}
