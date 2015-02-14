#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,ans,gmin,cmin,sum,cnt,p;
int cow[10005],scow[10005];
bool vis[10005];
int hash[100005];

int main()
{
    while (scanf("%d",&n)==1)
    {
        gmin=100000;
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&cow[i]);
            gmin=min(gmin,cow[i]);
            scow[i]=cow[i];
        }
        sort(scow+1,scow+n+1);
        for (int i=1;i<=n;i++) hash[scow[i]]=i;

        memset(vis,0,sizeof(vis));
        ans=0;
        for (int i=1;i<=n;i++)
        {
            if (vis[i]) continue;
            sum=cnt=0; cmin=100000;
            p=i;
            while (!vis[p])
            {
                sum+=cow[p];
                cmin=min(cmin,cow[p]);
                cnt++;
                vis[p]=1;
                p=hash[cow[p]];
            }
            ans += min(sum+(cnt-2)*cmin, sum+cmin+(cnt+1)*gmin);
        }
        printf("%d\n",ans);
    }
    return 0;
}