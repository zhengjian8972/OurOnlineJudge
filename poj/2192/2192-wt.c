/*************************************************
Author : wt
Time : 32MS
Memory : 552K
**************************************************/

#include <stdio.h>
#include <string.h>
#define maxn 205
char a[maxn], b[maxn], c[maxn << 1];
int dp[maxn][maxn];

int solve()
{
    int i, j, n = strlen(a), m = strlen(b);
    for(i = 0; i < n; i ++)
        if(a[i] == c[i])
            dp[i + 1][0] = 1;
    for(i = 0; i < m; i ++)
        if(b[i] == c[i])
            dp[0][i + 1] = 1;
    dp[0][0] = 1;
    for(i = 1; i <= n; i ++)
    {
        for(j = 1; j <= m; j ++)
        {
            if((dp[i - 1][j] && a[i - 1] == c[i + j - 1]) ||
               (dp[i][j - 1] && b[j - 1] == c[i + j - 1]))
                dp[i][j] = 1;
            else
                dp[i][j] = 0;
        }
    }
    return dp[n][m];
}

int main()
{
    int n, i;
    scanf("%d", &n);
    for(i = 1; i <= n; i ++)
    {
        scanf("%s%s%s", a, b, c);
        if(solve())
            printf("Data set %d: yes\n", i);
        else
            printf("Data set %d: no\n", i);
    }
    return 0;
}
