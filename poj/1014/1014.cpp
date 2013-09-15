/*************************************************
Author : wt
Time : 0MS
Memory : 732K
**************************************************/

#include <iostream>
using namespace std;

int a[7];
int b[7] = {1, 60, 30, 20, 30, 12, 10};

bool dfs(int left, int i){
    if(i == 0) return false;
    if(left < 0) return false;
    if(left == 0) return true;

    for(int j = 0; j <= a[i]; j++){
        if(dfs(left-j*i, i-1)) return true;
    }
    return false;
}

int main()
{
    int i, c = 1, sum, flag;
    while(1){
        for(i = 1; i < 7; i++){
            cin>>a[i];
        }
        sum = a[1]+a[2]*2+a[3]*3+a[4]*4+a[5]*5+a[6]*6;
        if(!sum) break;

        for(i = 1; i < 7; i++){
            a[i] = a[i] % b[i];
        }
        sum = a[1]+a[2]*2+a[3]*3+a[4]*4+a[5]*5+a[6]*6;

        flag = 0;
        if(!(sum&1)){
            flag = dfs(sum/2, 6);
        }

        cout<<"Collection #"<<c++<<":"<<endl;
        if(flag)
            cout<<"Can be divided."<<endl;
        else cout<<"Can't be divided."<<endl;
        cout<<endl;
    }
    return 0;
}
