#include <stdio.h>
int main()
{
   int n;
   printf("enter a number  ");
   scanf("%d",&n);
   int m=1;
   while(n !=0)
   {
       int b=n%10;
       m=m*b;
       n=n/10;
   }
   printf("%d", m);
   return 0;
}