#include <stdio.h>

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    while (n||m)
    {
        int ticket[10010]={0};
        int copy=0;
        for (int i=0;i<m;i++)
        {
            int t;
            scanf("%d",&t);
            ticket[t]++;
            if (ticket[t]==2)
                copy++;
        }
        printf("%d\n",copy);
        scanf("%d%d",&n,&m);
    }
    return 0;
}