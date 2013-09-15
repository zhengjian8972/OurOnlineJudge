/*************************************************
Author : wt
Time : 0MS
Memory : 732K
**************************************************/

#include <iostream>

using namespace std;

int na[4], nb[4];
int ca, cb;

int main()
{
    int n, a, b, i, j;
    cin>>n;

    while(n--){
        cin>>a>>b;

        for(i = 0; i < 4; i++){
            na[i] = a%10;
            a /= 10;
            nb[i] = b%10;
            b /= 10;
        }
        ca = cb = 0;

        for(int i = 0; i < 4; ++i){
            for(j = 0; j < 4; ++j){
                if(na[i] == nb[j]){
                    if(i == j)
                        ca++;
                    else
                        cb++;
                }
            }
        }

        cout<<ca<<'A'<<cb<<'B'<<endl;
    }
    return 0;
}
