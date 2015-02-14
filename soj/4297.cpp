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
typedef long long ll;

const int maxn = 110;
int n,ans;
int g[maxn][maxn];
int d[maxn];
int cnt;
bool vis[maxn];

void dfs(int u)
{
    for (int v=0;v<n;v++)
    {
        if (vis[v]) continue;
        if (g[u][v])
        {
            cnt++;
            vis[v]=1;
            dfs(v);
        }
    }
}

int main()
{
    while (scanf("%d",&n)==1)
    {
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                scanf("%d",&g[i][j]);
        for (int i=0;i<n;i++)
        {
            d[i]=0;
            for (int j=0;j<n;j++)
                if (g[i][j]) d[i]++;
        }
        ans=0;
        memset(vis,0,sizeof(vis));
        while (1)
        {

            for (int i=0;i<n;i++)
            {
                if (vis[i]) continue;
                if (d[i]==0) vis[i]=1;
                if (d[i]==1)
                {
                    ans++;
                    d[i]--;
                    vis[i]=1;
                    for (int j=0;j<n;j++)
                    {
                        if (g[i][j])
                        {
                            vis[j]=1;
                            g[i][j]=g[j][i]=0;
                            for (int k=0;k<n;k++)
                            {
                                if (g[j][k])
                                {
                                    g[j][k]=g[k][j]=0;
                                    d[k]--;
                                }
                            }
                            d[j]=0;
                            break;
                        }
                    }
                }
            }
            //for (int i=0;i<n;i++) printf("%d ",d[i]); puts("");
            bool dm=0;
            for (int i=0;i<n;i++)
                if (d[i]==1) dm=1;
            if (!dm) break;
        }
/*
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++) printf("%d ",g[i][j]);
            printf("\n");
        }
*/
        for (int i=0;i<n;i++)
        {
            if (vis[i]) continue;
            cnt=1;
            vis[i]=1;
            dfs(i);
            ans+=cnt/2;
        }
        printf("%d\n",ans);
    }
    return 0;
}