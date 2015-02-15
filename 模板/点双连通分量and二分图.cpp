//��˫��ͨ���� �� ����ͼ

const int maxn = 1010;
int pre[maxn], iscut[maxn], bccno[maxn], dfs_clock, bcc_cnt;
vector<int> g[maxn], bcc[maxn];
struct Edge
{
    int u,v;
    Edge(int uu,int vv) {u=uu; v=vv;}
};
stack<Edge> S;

int dfs(int u, int fa)
{
    int lowu = pre[u] = ++dfs_clock;
    int child = 0;
    for (int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        Edge e = Edge(u, v);
        if (!pre[v])
        {
            S.push(e);
            child++;
            int lowv = dfs(v, u);
            lowu = min(lowu, lowv);
            if (lowv >= pre[u])
            {
                iscut[u] = 1;
                bcc_cnt++; bcc[bcc_cnt].clear();
                while (1)
                {
                    Edge x = S.top(); S.pop();
                    if (bccno[x.u] != bcc_cnt) {bcc[bcc_cnt].push_back(x.u); bccno[x.u] = bcc_cnt;}
                    if (bccno[x.v] != bcc_cnt) {bcc[bcc_cnt].push_back(x.v); bccno[x.v] = bcc_cnt;}
                    if (x.u == u && x.v == v) break;
                }
            }
        }
        else if (pre[v] < pre[u] && v != fa)
        {
            S.push(e);
            lowu = min(lowu, pre[v]);
        }
    }
    if (fa <0 && child == 1) iscut[u] = 0;
    return lowu;
}

void find_bcc(int n)
{
    memset(pre, 0, sizeof(pre));
    memset(iscut, 0, sizeof(iscut));
    memset(bccno, 0, sizeof(bccno));
    dfs_clock = bcc_cnt = 0;
    for (int i = 0; i < n; i++)
        if (!pre[i]) dfs(i, -1);
}

int odd[maxn], color[maxn];
bool bipartite(int u, int b)
{
    for (int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        if (bccno[v] != b) continue;
        if (color[v] == color[u]) return 0;
        if (!color[v])
        {
            color[v] = 3 - color[u];
            if (!bipartite(v, b)) return 0;
        }
    }
    return 1;
}