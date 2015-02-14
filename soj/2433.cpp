#include <stdio.h>
#include <string.h>

int main()
{
    int t,cas;
    int h[2010];
    int len[2010];
    int n;
    scanf("%d",&t);
    for (cas = 0; cas < t; cas++)
    {
        memset(len,-1,sizeof(len));
        int max=0;
        scanf("%d",&n);
        for (int i=0;i<n;i++)
        {
            scanf("%d",&h[i]);
        }
        for (int i=0;i<n;i++)
        {
            int tempmax=0;
            for (int j=0;j<i;j++)
            {
                if (h[j]<h[i] && len[j]>tempmax)
                {
                    tempmax=len[j];
                }
            }
            len[i]=tempmax+1;
        }
        for (int i=0;i<n;i++)
        {
            if (len[i]>max)
            {
                max=len[i];
            }
        }
        printf("%d\n",max);
    }
    return 0;
}