#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
using namespace std;

const int maxn = 1010;
const int mod = 1991;
int T,n,m,k,l;
int a[maxn][maxn],b[maxn][maxn],c[maxn][maxn];

int main()
{
    int u,v;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d%d%d",&n,&m,&k,&l);
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for (int i=1;i<=n;i++) b[i][i]=1;
        while (m--)
        {
            scanf("%d%d",&u,&v);
            a[u][v]++;
        }
        while (k)
        {
            if (k&1)
            {
                for (u=1;u<=n;u++)
                    for (v=1;v<=n;v++)
                    {
                        int s=0;
                        for (int i=1;i<=n;i++)
                            s=(s+a[u][i]*b[i][v])%mod;
                        c[u][v]=s;
                    }
                for (u=1;u<=n;u++)
                    for (v=1;v<=n;v++)
                        b[u][v]=c[u][v];
            }
            for (u=1;u<=n;u++)
                for (v=1;v<=n;v++)
                {
                    int s=0;
                    for (int i=1;i<=n;i++)
                        s=(s+a[u][i]*a[i][v])%mod;
                    c[u][v]=s;
                }
            for (u=1;u<=n;u++)
                for (v=1;v<=n;v++)
                    a[u][v]=c[u][v];
            k>>=1;
        }
        while (l--)
        {
            scanf("%d%d",&u,&v);
            printf("%d\n",b[u][v]);
        }
    }
    return 0;
}
