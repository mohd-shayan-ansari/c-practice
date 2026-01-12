#include <stdio.h>
void greater(int a, int b);
int main()
{
    greater(1145,1184);
    return 0;
}
void greater(int a, int b)
{
    if(a>b)
    {
        printf("a is greater than b");
    }
    else
    {
        printf("b is greater than a");
    }
}