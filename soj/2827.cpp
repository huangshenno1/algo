#include <stdio.h>

int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        int difference=0;
        int m=2*n+1;
        int t;
        for (int i=0;i<m;i++)
        {
            scanf("%d",&t);
            difference=difference^t;
        }
        printf("%d\n",difference);
    }
    return 0;
}