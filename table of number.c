#include <stdio.h>

int main()
{
    int i;
    int a;
    printf("enter a number ");
    scanf("%d",&a);
    for(i=1; i<=10; i++)
    {
        printf("%d * %d = %d\n",a,i,a*i);
    }
    return 0;
}