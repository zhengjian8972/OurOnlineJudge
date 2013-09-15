/*************************************************
Author : wt
Time : 0MS
Memory : 732K
**************************************************/

#include <iostream>
using namespace std;

char str1[1001], str2[1001];
int m, n;

int min(int a, int b, int c){
    if(a > b) a = b;
    if(a > c) a = c;
    return a;
}

int calc(char *s1, char *s2){
	if(s1[0] && s2[0]){
		if(s1[0] == s2[0])
			return calc(s1+1, s2+1);
		else return min(calc(s1+1, s2)+1, calc(s1, s2+1)+1, calc(s1+1, s2+1)+1);
	}
	int i = 0;
	while(s2[i]) i++;
	return i;
}

int main()
{
    while(cin>>m){
    	cin>>str1>>n>>str2;
    	cout<<calc(str1, str2)<<endl;
    }
    return 0;
}
