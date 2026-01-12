#include <stdio.h>
void add(int a, int b, int c);
int main()
{
    add(54,85,95);
    return 0;
}
void add(int a,int b, int c)
{
    printf("%d",a+b+c);
}