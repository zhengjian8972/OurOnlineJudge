/*************************************************
Author : wt
Time : 47MS
Memory : 804K
**************************************************/

#include <iostream>
using namespace std;

int n, data[101][101], ans[101][101];

int main()
{
    int i, j, max = -1;
    cin>>n;
    for(i = 1; i <= n; ++i){
        for(j = 1; j <= i; ++j)
            cin>>data[i][j];
    }

    ans[1][1] = data[1][1];
    for(i = 2; i <= n; ++i){
        max = -1;
        for(j = 1; j <= i; ++j){
            if(i-1 >= j) ans[i][j] = ans[i-1][j] + data[i][j];
            if(j-1 >= 1)
                if(ans[i][j] < ans[i-1][j-1]+data[i][j])
                    ans[i][j] = ans[i-1][j-1]+data[i][j];
        }
    }

    for(i = 1; i <= n; ++i)
        if(max < ans[n][i])
            max = ans[n][i];
    cout<<max<<endl;
    return 0;
}
