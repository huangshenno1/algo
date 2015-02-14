#include <stdio.h>

int Sum(int n,int base)
{
    int s=0;
    while (n)
    {
        s+=n%base;
        n/=base;
    }
    return s;
}

int main()
{
    int temp;
    for (int n=2992;n<10000;n++)
    {
        temp=Sum(n,10);
        if (temp==Sum(n,12)&&temp==Sum(n,16))
            printf("%d\n",n);
    }
    return 0;
}