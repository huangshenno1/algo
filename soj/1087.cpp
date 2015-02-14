#include <cstdio>

int n,ans,i,j,k,r;
int fa[1510];

int main()
{
    while (~scanf("%d",&n) && n)
    {
        ans=0;
        for (i=0;i<n;i++)
            fa[i]=i;
        for (j=0;j<n;j++)
        {
            scanf("%d%d",&i,&k);
            while (k--)
            {
                scanf("%d",&r);
                fa[r]=i;
            }
        }
        for (i=n-1;i>=0;i--)
        {
            if (fa[i]==-1 || fa[fa[i]]==-1 || fa[i]==i)
                continue;
            fa[fa[i]]=-1;
            ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}