#include <stdio.h>

int main()
{
    int n,x;
    while (scanf("%d",&n)==1)
    {
        while (n--)
        {
            scanf("%x",&x);
            if (x&64) printf("-");
            else printf(".");
        }
        printf("\n");
    }
    return 0;
}