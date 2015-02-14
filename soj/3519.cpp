#include <stdio.h>

int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        int s=n*(n+1)/2*(n+2);
        printf("%d\n",s);
    }
    return 0;
}