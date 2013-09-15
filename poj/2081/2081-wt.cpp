/*************************************************
Author : wt
Time : 16MS
Memory : 3864K
**************************************************/

#include <iostream>
#include <set>
using namespace std;

int seq[500001];
bool a[30000001];

int main()
{
    seq[0] = 0;
    a[0] = true;
    int i = 1, tmp, n;
    for(; i <= 500000; ++i){
        tmp = seq[i-1] - i;
        if(tmp > 0 && !a[tmp])
            seq[i] = tmp;
        else seq[i] = seq[i-1] + i;

        a[seq[i]] = true;
    }

    while(cin>>n){
        if(n == -1) break;
        cout<<seq[n]<<endl;
    }
    return 0;
}
