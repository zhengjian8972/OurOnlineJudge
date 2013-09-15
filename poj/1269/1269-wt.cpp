/*************************************************
Author : wt
Time : 0MS
Memory : 728K
**************************************************/

#include <iostream>
#include <stdio.h>
#include <math.h>
#define isVertical(a, b, c, d) ((a)==(c))&&((b)!=(d))
using namespace std;

void oneLineIsVertical(double a, double b, double c, double d, double e){
    double  k1 = (b-d)/(a-c),
            t1 = b - k1*a;
    if(fabs(k1) < 0.00000001)
        printf("POINT %.2f %.2f\n", e, b);
    else printf("POINT %.2f %.2f\n", (e-t1)/k1, e);
}
void twoIsNomal(double a, double b, double c, double d, double e, double f, double g, double h){
    double  k1 = (b-d)/(a-c),
            k2 = (h-f)/(g-e),
            t1 = b - k1*a,
            t2 = h - k2*g;
    if(fabs(k1-k2) < 0.0000001){
        if(fabs(t1-t2) < 0.0000001)
            printf("LINE\n");
        else
            printf("NONE\n");
        return ;
    }
    double  x = (t2-t1)/(k1-k2);
    printf("POINT %.2f %.2f\n", x, k1*x+t1);
}

int main()
{
    int t, a1, b1, a2, b2, a3, b3, a4, b4;
    int flag1 = 0, flag2 = 0;
    cout<<"INTERSECTING LINES OUTPUT"<<endl;

    cin>>t;
    while(t--){
        cin>>a1>>b1>>a2>>b2>>a3>>b3>>a4>>b4;
        flag1 = flag2 = 0;

        if(isVertical(a1, b1, a2, b2)) flag1 = 1;
        if(isVertical(a3, b3, a4, b4)) flag2 = 1;

        if(flag1 == 1 || flag2 == 1){
            if(flag1 != 1){
                oneLineIsVertical(a1, b1, a2, b2, a3);
            }
            else if(flag2 != 1){
                oneLineIsVertical(a3, b3, a4, b4, a2);
            }
            else{
                if(a1 == a3) printf("LINE\n");
                else printf("NONE\n");
            }
        }
        else{
            twoIsNomal(a1, b1, a2, b2, a3, b3, a4, b4);
        }
    }

    cout<<"END OF OUTPUT"<<endl;
    return 0;
}
