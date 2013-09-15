/*************************************************
Author : wt
Time : 0MS
Memory : 728K
**************************************************/

#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

vector<int> maxLenValue;
int curMaxLen;

void fun(int n){
	int i = 0;
	while(i < curMaxLen && maxLenValue[i] >= n)
        i++;
    if(i == curMaxLen){
        maxLenValue.push_back(n);
        curMaxLen++;
    }
    else{
        maxLenValue[i] = n;
    }
}

int main()
{
    int n, c = 1;
    while(true){
        maxLenValue.clear();
    	curMaxLen = 0;
    	scanf("%d", &n);
    	if(n == -1) break;
    	while(n!=-1){
    	    if(curMaxLen == 0){
    	        maxLenValue.push_back(n);
    	        curMaxLen++;
    	    }
    	    else
                fun(n);
    		scanf("%d", &n);
    	}
    	cout<<"Test #"<<c++<<":"<<endl<<"  maximum possible interceptions: "<<curMaxLen<<endl<<endl;
    }
    return 0;
}
