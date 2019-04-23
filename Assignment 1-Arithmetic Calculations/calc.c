#include "calc.h"
#include<stdio.h>

int a =0;
void add (int x)
{
    a=a+x;
    printf("%d", a);
}


void multiply (int x)
{
    a=a*x;
    printf("%d",a);
}

void subtract (int x)
{
    a=a-x;
    printf("%d",a);
}

void divide (int x)
{
    a=a/x;
    printf("%d",a);
}

void mod (int x)
{
    a=a%x;
    printf("%d",a);
}

void clear()
{
    a=0;
}
