#include <stdio.h>
int main()
{
    int n=456;
    int rev=0;
    while(n!=0)
    {
       rev=(rev*10)+ n%10;
       n = n/10;
    }
    printf("%d",rev);
    return 0;
}