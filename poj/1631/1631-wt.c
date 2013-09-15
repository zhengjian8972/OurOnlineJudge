/*************************************************
Author : wt
Time : 94MS
Memory : 672K
**************************************************/

#include <stdio.h>
#include <stdlib.h>

int len;
int sequece[40001];
int maxLen[40001];
int maxLenValue[40001];

int main()
{
    int n, c, j, i, s, e, m;
    scanf("%d", &n);
    for(j = 1; j <= n; ++j){
        scanf("%d", &c);
        for(i = 0; i < c; ++i)
            scanf("%d", &sequece[i]);

        int curMaxLen = 1;
        maxLenValue[1] = sequece[0];

        for(i = 1; i < c; ++i){
            s = 1;  e = curMaxLen;
            do{
                m = (s+e)/2;
                if(maxLenValue[m] >= sequece[i])
                    e = m-1;
                else s = m+1;
            }while(s>=1 && e<=curMaxLen && s<=e);

            if(e < 1){
                maxLenValue[1] = sequece[i] < maxLenValue[1] ? sequece[i] : maxLenValue[1];
            }
            else if(e == curMaxLen){
                maxLenValue[++curMaxLen] = sequece[i];
            }
            else{
                maxLenValue[e+1] = sequece[i];
            }
        }

        printf("%d\n", curMaxLen);
    }
    return 0;
}
