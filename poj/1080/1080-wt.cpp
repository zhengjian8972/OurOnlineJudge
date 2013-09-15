/*************************************************
Author : wt
Time : 16MS
Memory : 796K
**************************************************/

#include <iostream>
using namespace std;

int matrix[200][200];
char seq1[101], seq2[101];
int ans[101][101], m, n;

int max(int a, int b, int c){
    if(a < b) a = b;
    if(a < c) a = c;
    return a;
}

void calc(){
    int i, j;
    ans[0][0] = 0;
    for(i = 1; i <= m; ++i)
        ans[i][0] = ans[i-1][0] + matrix[seq1[i-1]]['-'];
    for(j = 1; j <= n; ++j)
        ans[0][j] = ans[0][j-1] + matrix[seq2[j-1]]['-'];

    for(i = 1; i <= m; ++i){
        for(j = 1; j <= n; ++j){
            ans[i][j] = max(ans[i-1][j-1]+matrix[seq1[i-1]][seq2[j-1]],
                            ans[i][j-1]+matrix[seq2[j-1]]['-'],
                            ans[i-1][j]+matrix['-'][seq1[i-1]]);
        }
    }
}

int main()
{
    int t;
    void init();
    init();
    cin>>t;
    while(t--){
        cin>>m>>seq1;
        cin>>n>>seq2;
        calc();
        cout<<ans[m][n]<<endl;
    }
    return 0;
}

void init(){
    matrix['A']['C']=matrix['C']['A']=-1,
    matrix['A']['G']=matrix['G']['A']=-2,
    matrix['A']['T']=matrix['T']['A']=-1,
    matrix['C']['G']=matrix['G']['C']=-3,
    matrix['C']['T']=matrix['T']['C']=-2,
    matrix['T']['G']=matrix['G']['T']=-2,
    matrix['A']['-']=matrix['-']['A']=-3,
    matrix['C']['-']=matrix['-']['C']=-4,
    matrix['G']['-']=matrix['-']['G']=-2,
    matrix['T']['-']=matrix['-']['T']=-1,
    matrix['A']['A']=matrix['C']['C']=matrix['T']['T']=matrix['G']['G']=5,
    matrix['-']['-']=0;
}
