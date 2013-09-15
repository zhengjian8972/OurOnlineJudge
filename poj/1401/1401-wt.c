/*************************************************
Author : wt
Time : 329MS
Memory : 388K
**************************************************/

#include<stdio.h>
int main(){
   int n;
   long num, count;
   scanf("%d", &n);
   while(n--){
      scanf("%ld", &num);
      count = 0;
      while(num >= 5){
         count += num/5;
         num /= 5;
      }
      printf("%ld\n", count);
   }
   return 0;
}