#include <stdio.h>
#include <stdlib.h>

int main()
{
    int p, e, i, d, n, cas = 1;
    while(1){
        scanf("%d%d%d%d", &p, &e, &i, &d);
        if(p==e && e==i && i==d && d==-1)
            break;

        n=(5544*p+14421*e+1288*i-d+21252)%21252;
        if(n==0) n=21252;
        printf("Case %d: the next triple peak occurs in %d days.\n", cas++,n);
    }
    return 0;
}
