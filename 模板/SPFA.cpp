//SPFA

struct Edge
{
    int from,to;
    int d;
    Edge(int from, int to, int d) {this->from=from; this->to=to; this->d=d;}
};

const int INF = 0x3f3f3f3f;
const int maxn = 1010;
int n,m;
int dis[maxn];
int cnt[maxn];
bool vis[maxn];
vector<Edge> edges;
vector<int> g[maxn];

void init()
{
    for (int i=0;i<n;i++)
        g[i].clear();
    edges.clear();
}

void addEdge(int from,int to,int d)
{
    edges.push_back(Edge(from,to,d));
    int t=edges.size();
    g[from].push_back(t-1);
}

bool spfa(int st)
{
    for (int i=0;i<n;i++)
        dis[i]=INF;
    dis[st]=0;
    for (int i=0;i<n;i++)
        vis[i]=0;
    for (int i=0;i<n;i++)
        cnt[i]=0;
    queue<int> Q;
    while (!Q.empty()) Q.pop();
    Q.push(st);
    vis[st]=1;
    cnt[st]=1;
    while (!Q.empty())
    {
        int u = Q.front();
        for(unsigned int i=0;i<g[u].size();i++)
        {
			Edge &e=edges[g[u][i]];
			if (dis[e.to]==INF || dis[u]+e.d<dis[e.to]) //更改后距离更短,进行松弛操作
			{
			    dis[e.to]=dis[u]+e.d;
				if(!vis[e.to])
				{
					Q.push(e.to);
                    vis[e.to]=1;
                    cnt[e.to]++;
					if(cnt[e.to]>=n) //已经超过n次,出现负环
                        return 0;
				}
			}
		}
		Q.pop();
		vis[u]=0;
    }
    return 1;
}