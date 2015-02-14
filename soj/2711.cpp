#include <stdio.h>

int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)==2)
    {
        int r=n%m;
        if (r==0)
            printf("0\n");
        else
            printf("%d\n",m-r);
    }
    return 0;
}