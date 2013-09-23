/*************************************************
Author:zhengjian
Date:2013-09-22
Description:1011
Time: 32Ms
Memory:
**************************************************/

#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;
int sticks[64];
bool used[64];
int numOfSticks;
int target;
int num;

bool dfs(int cur, int left, int level)
{
    if(left==0) {
        if(level == num-1)
            return true;
        int i = numOfSticks-1;
        for(; used[i]; i--)
            ;
        used[i]=true;
        if(dfs(cur,target-sticks[i],level+1)) {
            return true;
        }
        used[i]= false;
        return false;
    } else {
        if(cur >= numOfSticks) return false;
	//此处还能优化，改不动了。。
        for(int j = numOfSticks-1; j>=0 ; j--) {
            if(used[j]) continue;
            if(sticks[j]==sticks[j+1] && !used[j+1]) continue;
            if(sticks[j] > left) continue;
            used[j]=true;
            if(dfs(j,left-sticks[j],level)) {
                return true;
            }
            used[j] =false;
        }
        return false;
    }
}

bool compare(int a, int b)
{
    return a < b;
}

int main()
{
    while(cin>>numOfSticks) {
        if(numOfSticks==0) {
            break;
        }

        int sum=0;
        for(int i =0; i<numOfSticks ; i++) {
            scanf("%d",&sticks[i]);
            sum +=sticks[i];
        }
        int halfSum = sum/2;
        sort(sticks,sticks+numOfSticks,compare);
        //dfs
        bool alreadyGet = false;
        for( target=sticks[numOfSticks-1] ; target<= halfSum ; target++) {
            if(sum% target ==0) {
                num = sum/target;
                used[numOfSticks-1] = true;
                if(dfs(numOfSticks-1,target-sticks[numOfSticks-1],0) ) {
                    printf("%d\n",target);
                    alreadyGet = true;
                    break;
                }
                used[numOfSticks-1] = false;
            }
        }
        if(!alreadyGet) {
            cout<<sum<<endl;
        }
        memset(used,0,numOfSticks);
    }

    return 0;
}

