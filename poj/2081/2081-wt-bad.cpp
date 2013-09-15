/*************************************************
Author : wt
Time : 2407MS
Memory : 19668K
**************************************************/

#include <iostream>
#include <set>
using namespace std;

int seq[500001];
set<int> s;

int main()
{
    seq[0] = 0; s.insert(0);
    int i = 1, tmp, n;
    for(; i <= 500000; ++i){
        tmp = seq[i-1] - i;
        if(tmp > 0 && s.find(tmp)==s.end())
            seq[i] = tmp;
        else seq[i] = seq[i-1] + i;

        s.insert(seq[i]);
    }

    while(cin>>n){
        if(n == -1) break;
        cout<<seq[n]<<endl;
    }
    return 0;
}