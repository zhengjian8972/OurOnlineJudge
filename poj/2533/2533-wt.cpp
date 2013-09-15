/*************************************************
Author : wt
Time : 16MS
Memory : 728K
**************************************************/

#include <iostream>
#include <stdio.h>
using namespace std;

int maxLenValue[1001];
int curMaxLen;

int main()
{
    int n, p, s, e, m;
    scanf("%d", &n);
    scanf("%d", &p);
    maxLenValue[1] = p;
    curMaxLen = 1;
    n--;
    while(n--){
        scanf("%d", &p);

        s = 1;  e = curMaxLen;
        do{
    	    m = (s+e)/2;
    	    if(maxLenValue[m] >= p)
                e = m-1;
            else s = m+1;
    	}while(s>=1 && e<=curMaxLen && s<=e);
    	if(e < 1){
    	    maxLenValue[1] = p < maxLenValue[1] ? p : maxLenValue[1];
    	}
    	else if(e == curMaxLen){
    	    maxLenValue[++curMaxLen] = p;
    	}
    	else{
    	    maxLenValue[e+1] = p;
    	}
    }
    cout<<curMaxLen<<endl;
    return 0;
}
