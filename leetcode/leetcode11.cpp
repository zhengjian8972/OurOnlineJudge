#include<iostream>
#define N 10001
#include<vector>
using namespace std;

/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
Find two lines, which together with x-axis forms a container, such that the container contains the most water.
Note: You may not slant the container.

ËãÊÇÄ¾Í°Ô­Àí
*/

int maxArea(vector<int> &height) {

    int length = height.size();
    int front =0;
    int back =  length - 1 ;

    int maxVolum = 0 ;

    int tempVolum;
    while(front< back){
        tempVolum = (back-front) * (height[front] > height[back]? height[back] : height[front]);
        if(tempVolum > maxVolum)
            maxVolum = tempVolum;

        if(height[front] > height[back]){
            back--;
        }else{
            front++;
        }
    }
    return maxVolum;
}

int main()
{
    vector<int> height ;
    height.push_back(1);
    height.push_back(2);
    height.push_back(3);
    height.push_back(1);
    cout<< maxArea(height);
    return 0;
}
