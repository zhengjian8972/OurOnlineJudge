/*************************************************
Author : wt
Time : 47MS
Memory : 728K
**************************************************/

#include <iostream>
using namespace std;

int a[7];

int main()
{
    int count, tmp;
    while((cin>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6]) && (a[1]||a[2]||a[3]||a[4]||a[5]||a[6])){
        count = a[6];
        a[6] = 0;

        tmp = a[1] / 11;
        count += a[5];
        if(a[5] <= tmp){
            a[1] -= a[5] * 11;
        }
        else{
            a[1] = 0;
        }
        a[5] = 0;

        tmp = a[4] * 5;
        count += a[4];
        if(a[2] >= tmp){
            a[2] -= tmp;
        }
        else{
            int left = (tmp-a[2])*4;
            a[1] = a[1] > left ? a[1]-left : 0;
            a[2] = 0;
        }
        a[4] = 0;

        count += a[3] / 4;
        a[3] %= 4;

        if(a[3]){
            if(a[3] == 1){
                if(a[2] > 5){
                    a[2] -= 5;
                    a[1] -= 7;
                }
                else{
                    a[1] -= (27-a[2]*4);
                    a[2] = 0;
                }
            }
            else if(a[3] == 2){
                if(a[2] > 3){
                    a[2] -= 3;
                    a[1] -= 6;
                }
                else{
                    a[1] -= (18-a[2]*4);
                    a[2] = 0;
                }
            }
            else{
                a[2] -= 1;
                a[1] -= 5;
            }
            count++;
        }

        if(a[2] < 0)
            a[2] = 0;
        count += a[2] / 9;
        a[2] %= 9;
        if(a[2]){
            a[1] -= (36-a[2]*4);
            count++;
        }

        if(a[1] < 0) a[1] = 0;
        count += a[1] / 36;
        a[1] %= 36;
        if(a[1])
            count++;

        cout<<count<<endl;
    }
    return 0;
}
