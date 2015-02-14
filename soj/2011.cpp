#include <stdio.h>

int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        int m=1;
        int d=1;
        while (m%n)
        {
            m=(10*m+1)%n;
            d++;
        }
        printf("%d\n",d);
    }
    return 0;
}