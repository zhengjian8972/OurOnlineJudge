#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

typedef struct item{
    int v;
    char s[51];
}Item;

Item items[101];
char dnas[101][51];
int c;
char t1[101], t2[101];

void merge(char* d, int s, int m, int e){
    int i, j, k;
    for(i = s; i <= m; ++i){
        t1[i] = d[i];
    }
    for(j = m+1; j <= e; ++j){
        t2[j] = d[j];
    }

    k = i = s;  j = m+1;
    while(i<=m && j<=e){
        if(t1[i] <= t2[j]){
            d[k++] = t1[i++];
        }
        else{
            c += (m-i+1);
            d[k++] = t2[j++];
        }
    }
    while(i <= m){
        d[k++] = t1[i++];
    }
    while(j <= e){
        d[k++] = t2[j++];
    }
}

void mergeSort(char* d, int s, int e){
    if(s < e){
        mergeSort(d, s, (s+e)/2);
        mergeSort(d, (s+e)/2+1, e);
        merge(d, s, (s+e)/2, e);
    }
}

bool comp(const Item &i1, const Item &i2){
    return i1.v < i2.v;
}

int main()
{
    int l, m, i;
    scanf("%d%d", &l, &m);
    for(i = 0; i < m; ++i){
        scanf("%s", dnas[i]);
        c = 0;
        strcpy(items[i].s, dnas[i]);
        mergeSort(dnas[i], 0, l-1);
        items[i].v = c;
    }
    sort(items, items+m, &comp);
    for(i = 0; i < m; ++i){
        printf("%s\n", items[i].s);
    }
    return 0;
}
