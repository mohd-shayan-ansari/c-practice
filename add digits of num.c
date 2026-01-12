#include <stdio.h>
#include <conio.h>
int main()
{
   int n;
   printf("enter a number  ");
   scanf("%d",&n);
   int sum=0;
   while(n !=0)
   {
       int b=n%10;
       sum=sum+b;
       n=n/10;
   }
   printf("addition of digits in this number is:- %d", sum);
   getch();
}