#include <stdio.h>
int main()
{
    int n;
    printf("enter a number ");
    scanf("%d",&n);
    int copy=n;
    int sum=0;
    while(n!=0)
    {
        int b=n%10;
        sum=sum+b*b*b;
        n=n/10;
    }
    if(sum==copy)
    {
      printf("this number is armstrong");
    }
    else
    {
        printf("this number is not armstrong");
    }
      return 0;
}