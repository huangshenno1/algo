#include <cstdio>
#include <cstring>

int T,n;
int a[300];
int ans;
int vis[1000000];

bool solve()
{
    for (int i=0;i<n;i++)
    {
        int t=a[i]%ans;
        if (vis[t]==ans)
            return 0;
        vis[t]=ans;
    }
    return 1;
}

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        for (int i=0;i<n;i++)
            scanf("%d",&a[i]);
        ans=n;
        memset(vis,0,sizeof(vis));
        while (!solve()) ans++;
        printf("%d\n",ans);
    }
    return 0;
}