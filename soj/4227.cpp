#include <cstdio>

int main()
{
    int T,a[20],i,ans;
    scanf("%d",&T);
    while (T--)
    {
        for (i=0;i<20;i++)
            scanf("%d",&a[i]);
        for (i=1;i<20;i++)
        {
            if (a[i]!=a[0])
            {
                ans=i;
                break;
            }
        }
        for (i=ans;i<20;i++)
        {
            if (a[i]==a[0])
            {
                ans=-1;
                break;
            }
        }
        if (ans==-1) printf("-1\n");
        else printf("%d.5\n",ans-1);
    }
    return 0;
}