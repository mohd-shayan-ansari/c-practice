#include <stdio.h>
int main()
{
    FILE*fp;
    fp=fopen("demo.txt","W");
    fprintf(fp,"Shayan");
    return 0;
}