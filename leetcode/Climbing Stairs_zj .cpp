/*************************************************
Author:zhengjian
Date:2013-09-16
Description:Climbing Stairs
Time:
Memory:
**************************************************/

#include<iostream>
#define N 10001
#include<vector>
using namespace std;

/*
Climbing Stairs

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

µÝ¹é¹ûÈ»Âýµ½±¬
*/

int climbStairs(int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int value [n+1];
    value[1] = 1;
    value[2] = 2;
    for(int i =3; i<=n; i++) {
        value[i] = value[i-1] + value[i-2];
    }
    return value[n];
}

int main()
{
    cout<<climbStairs(8);
    return 0;
}
