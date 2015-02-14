#include <stdio.h>

int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        int s=0;
        int t;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&t);
            s+=t;
        }
        s=s-n+1;
        scanf("%d",&t);
        if (s==t)
            printf("GREAT!\n");
        else printf("POOR!\n");
    }
    return 0;
}