#include <stdio.h>
void rev(int a);
int main()
{
    rev(345678);
    return 0;
}
void rev(int a)
{
    int rev=0;
    while(a!=0)
    {
        int b=a%10;
        rev=(rev*10)+b;
        a=a/10;
    }
    printf("%d",rev);
}