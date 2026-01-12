#include <stdio.h>
#include <conio.h>
int main()
{
    int a,b=0;
    char name[50];
    printf("enter a string");
    gets(name);
    for(a=0;name[a]!='\0';a++);
    for(a--;a>=0;a--)
        printf("%c",name[a]);
    getch();
}// not sure of this code