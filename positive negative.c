#include <stdio.h>
int main()
{
    int a;
    printf("enter a no ");
    scanf("%d",&a);
    if (a>=0)
    {
        printf("this is a positive no.");
    }
    else
    {
        printf("this is a negative no.");
    }
    return 0;
}