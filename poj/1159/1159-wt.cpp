/*************************************************
Author : wt
Time : 1375MS
Memory : 41204K
**************************************************/

#include <iostream>
using namespace std;

#define min(a, b) (a) > (b) ? (b) : (a)

int n;
char str[5001];
short int ans[5001][5001];

void calc(){
    int i, s, e;
    for(i = 0; i < n; ++i)
        ans[i][i] = 0;

    for(i = 1; i < n; ++i){
        for(s = 0, e = i; e < n; ++s, ++e){
            if(str[s] == str[e]){
                if(e > s-1)
                    ans[s][e] = ans[s+1][e-1];
                else
                    ans[s][e] = 0;
            }
            else
                ans[s][e] = min(ans[s+1][e]+1, ans[s][e-1]+1);
        }
    }
}

int main()
{
    cin>>n;
    cin>>str;
    calc();
    cout<<ans[0][n-1]<<endl;
    return 0;
}
