#include <cstdio>

int main()
{
    int cas,T=1,ans,t,n,i;
    scanf("%d",&cas);
    while (cas--)
    {
        printf("Case %d: ",T++);
        scanf("%d",&n);
        ans=0;
        for (i=1;i<=n;i++)
        {
            scanf("%d",&t);
            if (i%3==2 || i%6==0) ans^=t;
        }
        if (ans) printf("Alice\n");
        else printf("Bob\n");
    }
    return 0;
}