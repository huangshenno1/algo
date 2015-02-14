#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef int ll;

struct Edge
{
    int v;
    ll in, out;
    Edge(int v, ll in, ll out) : v(v), in(in), out(out) {}
};

struct Node
{
    int u;
    ll in, out;
    Node(int u, ll in, ll out) : u(u), in(in), out(out) {}
    bool operator < (const Node &rhs) const
    {
        if (out == rhs.out) return in > rhs.in;
        return out > rhs.out;
    }
};

const int maxn = 4010;
int n, m, q;
vector<Edge> g[maxn];
ll in[maxn], out[maxn];
bool vis[maxn];

void dijkstra(int st)
{
    for (int i=0;i<n;i++) in[i] = out[i] = -1;
    for (int i=0;i<n;i++) vis[i] = 0;
    in[st] = out[st] = 0;
    priority_queue<Node> Q;
    Q.push(Node(st, 0, 0));
    while (!Q.empty())
    {
        Node top = Q.top(); Q.pop();
        int u = top.u;
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i=0;i<g[u].size();i++)
        {
            int v = g[u][i].v;
            ll din = g[u][i].in, dout = g[u][i].out;
            if (out[v] == -1 || out[v] > out[u] + dout || (out[v] == out[u] + dout && in[v] > in[u] + din))
            {
                out[v] = out[u] + dout;
                in[v] = in[u] + din;
                Q.push(Node(v, in[v], out[v]));
            }
        }
    }
}

int main()
{
    int u, v;
    ll dis;
    char ch;
    while (scanf("%d%d%d", &n, &m, &q) == 3)
    {
        for (int i=0;i<n;i++) g[i].clear();
        for (int i=0;i<m;i++)
        {
            scanf("%d%d%d %c", &u, &v, &dis, &ch);
            if (ch == 'I')
            {
                g[u].push_back(Edge(v, dis, 0));
                g[v].push_back(Edge(u, dis, 0));
            }
            else
            {
                g[u].push_back(Edge(v, 0, dis));
                g[v].push_back(Edge(u, 0, dis));
            }
        }
        while (q--)
        {
            scanf("%d%d", &u, &v);
            dijkstra(u);
            if (out[v] == -1) puts("IMPOSSIBLE");
            else printf("%d %d\n", out[v], in[v]+out[v]);
        }
    }
    return 0;
}
