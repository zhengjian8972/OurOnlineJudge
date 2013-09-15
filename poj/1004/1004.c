/*************************************************
Author : wt
Time : 0MS
Memory : 400K
**************************************************/

#include <stdio.h>
#include <stdlib.h>
int main()
{
    double num, sum = 0.0;
    int i = 12;
    while(i--){
        scanf("%lf", &num);
        sum += num;
    }
    printf("$%.02f\n", sum/12);
    return 0;
}
