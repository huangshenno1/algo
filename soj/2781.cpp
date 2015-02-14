#include <stdio.h>

int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        int s=0;
        int t;
        for (int i=1;i<n;i++)
        {
            s=s^i;
            scanf("%d",&t);
            s=s^t;
        }
        s=s^n;
        printf("%d\n",s);
    }
    return 0;
}