#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 510;
int T,n,m,ans,cnt,lim;
int pa[maxn];
struct Node
{
    int x,y,h;
}node[maxn];
struct Edge
{
    int from,to,d;
    bool operator <(const Edge &o) const
    {
        return d<o.d;
    }
}edge[maxn*maxn];

int findset(int x)
{
    if (pa[x]==x) return x;
    return pa[x]=findset(pa[x]);
}
bool mergeset(int x,int y,int d)
{
    x=findset(x);
    y=findset(y);
    if (x==y) return 0;
    pa[y]=x;
    ans+=d;
    return 1;
}

int dis(int i,int j)
{
    return abs(node[i].x-node[j].x)+abs(node[i].y-node[j].y)+abs(node[i].h-node[j].h);
}

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        ans=0;
        for (int i=0;i<=n;i++)
            pa[i]=i;

        for (int i=1;i<=n;i++)
            scanf("%d%d%d",&node[i].x,&node[i].y,&node[i].h);
        scanf("%d%d%d%d",&lim,&node[0].x,&node[0].y,&node[0].h);

        m=0;
        for (int i=0;i<n;i++)
            for (int j=i+1;j<=n;j++)
            {
                edge[m].from=i;
                edge[m].to=j;
                edge[m].d=dis(i,j);
                m++;
            }

        sort(edge,edge+m);
        cnt=0;
        for (int i=1;i<=n;i++)
        {
            if (node[i].h>lim)
            {
                mergeset(0,i,dis(0,i));
                cnt++;
            }
        }

        for (int i=0;i<m;i++)
        {
            if (mergeset(edge[i].from, edge[i].to, edge[i].d))
                cnt++;
            if (cnt==n) break;
        }
        printf("%d\n",ans);
    }
    return 0;
}