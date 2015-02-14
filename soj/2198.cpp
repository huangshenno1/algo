#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 510;
int T,n,sz,c;
int g[maxn][maxn];
int fa[maxn];

struct road
{
    int a,b;
    int dis;

    bool operator < (const road x) const
    {
        return dis < x.dis;
    }
}r[maxn*maxn];

int findset(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = findset(fa[x]);
}

void mergeset(int x, int y)
{
    x = findset(x);
    y = findset(y);
    if (x != y)
        fa[y] = x;
}

int main()
{
    int i,j;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        sz=0;
        for (i=1;i<=n;i++)
        {
            fa[i]=i;
            for (j=1;j<=n;j++)
            {
                scanf("%d",&g[i][j]);
                if (i<j) {r[sz].a=i;r[sz].b=j;r[sz].dis=g[i][j];sz++;}
            }
        }
        sort(r,r+sz);
        i=0;c=1;
        mergeset(r[i].a,r[i].b);
        for (i=1;i<sz && c<n-1;i++)
        {
            if (findset(r[i].a)!=findset(r[i].b))
            {
                mergeset(r[i].a,r[i].b);
                c++;
            }
        }
        printf("%d\n",r[i-1].dis);
    }
    return 0;
}