#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int maxn = 1005;
int n,m;
vector<int> g[maxn];
int pre[maxn],lowlink[maxn],sccno[maxn],clk,cnt;
stack<int> stk;

void dfs(int u)
{
    pre[u]=lowlink[u]=++clk;
    stk.push(u);
    for (int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if (!pre[v])
        {
            dfs(v);
            lowlink[u]=min(lowlink[u],lowlink[v]);
        }
        else if (!sccno[v])
        {
            lowlink[u]=min(lowlink[u],pre[v]);
        }
    }
    if (lowlink[u]==pre[u])
    {
        cnt++;
        while (1)
        {
            int x=stk.top(); stk.pop();
            sccno[x]=cnt;
            if (x==u) break;
        }
    }
}

void find_scc()
{
    clk=cnt=0;
    while (!stk.empty()) stk.pop();
    memset(sccno,0,sizeof(sccno));
    memset(pre,0,sizeof(pre));
    for (int i=0;i<n;i++)
        if (!pre[i]) dfs(i);
}

int main()
{
    int u,v;
    bool oh;
    while (scanf("%d%d",&n,&m)==2)
    {
        oh=0;
        for (int i=0;i<n;i++) g[i].clear();
        for (int i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);u--;v--;
            g[u].push_back(v);
            if (u==v) oh=1;
        }
        if (oh) {puts("-1");continue;}
        find_scc();
        if (n>cnt) puts("2");
        else puts("1");
    }
    return 0;
}