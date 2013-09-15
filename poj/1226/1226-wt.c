/*************************************************
Author : wt
Time : 141MS
Memory : 380K
**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[101][101];
char sub[101];
char revSub[101];
int t, n, max;

void switchStr(int i){
    char tmp[101];
    strcpy(tmp, str[0]);
    strcpy(str[0], str[i]);
    strcpy(str[i], tmp);
}

void reverse(char *from, char *to){
    int len = strlen(from), i;
    for(i = 0; i < len; i++){
        to[len-i-1] = from[i];
    }
    to[len] = '\0';
}

int main()
{
    int i, j, k, len, flag;

    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        max = 0;
        for(i = 0; i < n; i++){
            scanf("%s", &str[i]);
            if(strlen(str[0]) > strlen(str[i]))
                switchStr(i);
        }

        len = strlen(str[0]);
        for(i = 0; i < len; i++){
            for(j = 1; j <= len-i; j++){
                flag = 1;

                for(k = 0; k < j; k++)
                    sub[k] = str[0][i+k];
                sub[k] = '\0';
                reverse(sub, revSub);

                for(k = 1; k < n; ++k){
                    if(!flag) break;
                    if(!strstr(str[k], sub) && !strstr(str[k], revSub))
                        flag = 0;
                }
                if(flag){
                    if(j > max)
                        max = j;
                }
            }
        }
        printf("%d\n", max);
    }
    return 0;
}
