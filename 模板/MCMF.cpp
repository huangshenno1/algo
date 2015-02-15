//MinCostMaxFlow

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Edge
{
    int from, to, cap, flow, cost;
    Edge(int ff,int tt,int cc,int fl,int co) {from=ff; to=tt; cap=cc; flow=fl; cost=co;}
};

const int INF = 0x3f3f3f3f;
const int maxn = 5010;
int n, m, s, t;
vector<Edge> edges;
vector<int> g[maxn];
int inq[maxn], d[maxn], p[maxn], a[maxn];

void init()
{
    edges.clear();
    for (int i = 0; i < n; i++) g[i].clear();
}

void addEdge(int from, int to, int cap, int cost)
{
    edges.push_back(Edge(from, to, cap, 0, cost));
	edges.push_back(Edge(to, from, 0, 0, -cost));
	m = edges.size();
	g[from].push_back(m-2);
	g[to].push_back(m-1);
}

bool BellmanFord(int s, int t, int &flow, int &cost)
{
    for (int i = 0; i < n; i++) d[i] = INF;
    memset(inq, 0, sizeof(inq));
    d[s] = 0; inq[s] = 1; p[s] = 0; a[s] = INF;
    queue<int> Q;
    Q.push(s);
    while (!Q.empty())
    {
        int u = Q.front(); Q.pop();
        inq[u] = 0;
        for (int i = 0; i < g[u].size(); i++)
        {
            Edge& e = edges[g[u][i]];
			if (e.cap > e.flow && d[e.to] > d[u] + e.cost)
			{
				d[e.to] = d[u] + e.cost;
				p[e.to] = g[u][i];
				a[e.to] = min(a[u], e.cap - e.flow);
				if (!inq[e.to]) {Q.push(e.to); inq[e.to] = 1;}
			}
        }
    }
    if (d[t] == INF) return 0;
    flow += a[t];
    cost += d[t] * a[t];
    int u = t;
    while (u != s)
    {
        edges[p[u]].flow += a[t];
        edges[p[u]^1].flow -=a[t];
        u = edges[p[u]].from;
    }
    return 1;
}

int mincost(int s, int t)
{
    int flow = 0, cost = 0;
    while (BellmanFord(s, t, flow, cost));
    return cost;
}