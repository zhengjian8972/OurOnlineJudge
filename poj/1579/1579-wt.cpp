/*************************************************
Author : wt
Time : 0MS
Memory : 760K
**************************************************/

#include <iostream>
using namespace std;

int w[21][21][21];

void init(){
    int i, j, k;
    for(i = 0; i <= 20; i++){
        for(j = 0; j <= 20; j++){
            w[0][i][j] = w[i][0][j] = w[i][j][0] = 1;
        }
    }

    for(k = 1; k <= 20; ++k){
        for(j = 1; j <= 20; ++j){
            for(i = 1; i <= 20; ++i){
                if(i<j && j<k)
                    w[i][j][k] = w[i][j][k-1] + w[i][j-1][k-1] - w[i][j-1][k];
                else
                    w[i][j][k] = w[i-1][j][k] + w[i-1][j-1][k] + w[i-1][j][k-1] - w[i-1][j-1][k-1];
            }
        }
    }
}

int fun(int a, int b, int c){
    if(a<=0 || b<=0 || c<=0)
        return 1;

    if(a>20 || b>20 || c>20)
        return w[20][20][20];

    return w[a][b][c];
}
int main()
{
    int a, b, c;
    init();

    while(cin>>a>>b>>c){
        if(a==-1 && b==-1 && c==-1) break;
        else cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<fun(a, b, c)<<endl;
    }
    return 0;
}
