/*************************************************
Author : wt
Time : 0MS
Memory : 704K
**************************************************/

#include <iostream>
using namespace std;

int han3[13] = {0, 1, 3, 7, 15, 31, 63, 127, 255, 511, 1023, 2047, 4095};
int han4[13] = {0, 1, 3, 5, 9, 13, 17, 25, 33, 41, 49, 65, 81};

void init(){
    int i, k, min, tmp;

    han4[1] = 1;    han4[2] = 3;    han4[3] = 5;
    for(i = 4; i <= 12; ++i){
        min = 0x3fffffff;
        for(k = 1; k < i; ++k){
            tmp = han4[k] + han3[i-k] + han4[k];
            if(min > tmp)
                min = tmp;
        }
        han4[i] = min;
    }
}

int main()
{
//    init();

    for(int i = 1; i <= 12; i++)
        cout<<han4[i]<<endl;
    return 0;
}
