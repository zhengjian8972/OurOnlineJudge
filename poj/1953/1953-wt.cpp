/*************************************************
Author : wt
Time : 0MS
Memory : 728K
**************************************************/

#include <iostream>
using namespace std;

int count[46][2];

int main()
{
    int i, n, t, m;

    count[1][0] = count[1][1] = 1;
    for(i = 2; i <= 45; ++i){
        count[i][0] = count[i-1][0] + count[i-1][1];
        count[i][1] = count[i-1][0];
    }

    cin>>n;
    for(t = 1; t <= n; ++t){
        cin>>m;
        cout<<"Scenario #"<<t<<":"<<endl<<count[m][0] + count[m][1]<<endl<<endl;
    }
    return 0;
}
