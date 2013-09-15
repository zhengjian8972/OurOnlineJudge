/*************************************************
Author : wt
Time : 641MS
Memory : 3404K
**************************************************/

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef struct word{
    int num;
    int count;
    struct word *left;
    struct word *right;
}Word;

Word *head;
int letter[25] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9};
int c;

bool comp(const Word &w1, const Word &w2){
    return w1.num < w2.num;
}

void print(Word *cur){
    if(!cur)
        return;
    print(cur->left);
    if(cur->count != 1){
        printf("%03d-%04d %d\n", cur->num/10000, cur->num%10000, cur->count);
        c++;
    }
    print(cur->right);
}

int main()
{
    int n, i, j, num;
    char s[50];
    c = 0;
    scanf("%d/n", &n);
    for(i = 0; i < n; ++i){
        scanf("%s", s);
        num = 0;
        for(j = 0; s[j]; ++j){
            if(s[j]>='A' && s[j]<='Z')
                num = num*10+letter[s[j]-'A'];
            else if(s[j]>='0' && s[j]<='9')
                num = num*10+s[j]-'0';
        }
        Word **cur = &head;
        while(*cur && (*cur)->num!=num){
            if((*cur)->num > num)
                cur = &(*cur)->left;
            else cur = &(*cur)->right;
        }
        if(!*cur){
            *cur = (Word *)malloc(sizeof(Word));
            (*cur)->left = (*cur)->right = 0;
            (*cur)->count = 0;
        }
        (*cur)->num = num;
        (*cur)->count++;
    }
    print(head);
    if(!c){
        printf("No duplicates.\n");
    }
    return 0;
}
