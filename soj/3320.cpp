#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    for (int iCase=0;iCase<t;iCase++)
    {
        int n;
        scanf("%d",&n);
        int g[50010];
        int max=0;
        scanf("%d",&g[0]);
        for (int i=1;i<n;i++)
        {
            scanf("%d",&g[i]);
            int temp=g[i]+g[i-1];
            if (temp>max)
                max=temp;
        }
        printf("%d\n",max);
    }
    return 0;
}