#include <stdio.h>

int F91(int n)
{
    if (n>100)
        return n-10;
    else return 91;
}

int main()
{
    int n;
    scanf("%d",&n);
    while (n)
    {
        printf("f91(%d) = %d\n",n,F91(n));
        scanf("%d",&n);
    }
    return 0;
}