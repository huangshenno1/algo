#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100;
const int INF = 10000;
int n,a,b;
int g[maxn][maxn],dis[maxn];
bool vis[maxn];

int main()
{
    int i,j,k,d;
    while (scanf("%d%d%d",&n,&a,&b)==3)
    {
        a--; b--;
        for (i=0;i<n;i++)
            for (j=0;j<n;j++)
                g[i][j]=INF;
        for (i=0;i<n;i++)
            g[i][i]=0;
        for (i=0;i<n;i++)
        {
            scanf("%d",&k);
            if (!k) continue;
            scanf("%d",&j); g[i][j-1]=0;
            while (--k) {scanf("%d",&j); g[i][j-1]=1;}
        }
        for (i=0;i<n;i++) {dis[i]=g[a][i]; vis[i]=0;}
        dis[a]=0; vis[a]=1;
        for (i=0;i<n;i++)
        {
            if (vis[i]) continue;
            j=i; d=INF;
            for (k=0;k<n;k++)
                if (!vis[k] && dis[k]<d) {d=dis[k]; j=k;}
            vis[j]=1;
            for (k=0;k<n;k++)
                if (!vis[k] && dis[k]>dis[j]+g[j][k]) dis[k]=dis[j]+g[j][k];
        }
        if (dis[b]>=INF) printf("KK can not find his friend.\n");
        else printf("%d\n",dis[b]);
    }
    return 0;
}
