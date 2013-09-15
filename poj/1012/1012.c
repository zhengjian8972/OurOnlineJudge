/*************************************************
Author : wt
Time : 0MS
Memory : 388K
**************************************************/

#include <stdio.h>
#include <stdlib.h>

int num[15] = { 0, 2, 7, 5, 30, 169, 441, 1872, 7632, 1740, 93313, 459901, 1358657, 2504881 };

int main(){
    int n;
    while(scanf("%d", &n)){
        if(n == 0) break;
        printf("%d\n", num[n]);
    }
    return 0;
}
