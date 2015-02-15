//cut and bridge

const int maxn = 110;
int pre[maxn], iscut[maxn], isbridge[maxn][maxn], low[maxn], dfs_clock;
vector<int> g[maxn];

int dfs(int u, int fa)
{
    int lowu = pre[u] = ++dfs_clock;
    int child = 0;
    for (int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        if (!pre[v])
        {
            child++;
            int lowv = dfs(v, u);
            lowu = min(lowu, lowv);
            if (lowv >= pre[u]) iscut[u] = 1;
            if (lowv > pre[u]) isbridge[u][v] = isbridge[v][u] = 1;
        }
        else if (pre[v] < pre[u] && v != fa) lowu = min(lowu, pre[v]);
    }
    if (fa <0 && child == 1) iscut[u] = 0;
    low[u] = lowu;
    return lowu;
}