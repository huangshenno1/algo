#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 1010;

int n,m,ans;
struct Node
{
    int no,l,t;
    bool operator < (const Node o) const {return t>o.t;}
}node[maxn];
vector<int> edge[maxn];
bool vis[maxn];

int main()
{
    while (~scanf("%d",&n))
    {
        for (int i=1;i<=n;i++)
        {
            edge[i].clear();
            node[i].t=0;
            vis[i]=0;
            node[i].no=i;
            scanf("%d",&node[i].l);
            scanf("%d",&m);
            while (m--)
            {
                int temp;
                scanf("%d",&temp);
                edge[i].push_back(temp);
            }
        }

        priority_queue<Node> Q;
        ans=node[1].t=node[1].l;
        vis[1]=1;
        Q.push(node[1]);
        while (!Q.empty())
        {
            int i=Q.top().no;
            Q.pop();
            for (int k=0;k<edge[i].size();k++)
            {
                int j=edge[i][k];
                if (!vis[j])
                {
                    node[j].t=node[i].t+node[j].l;
                    if (node[j].t>ans) ans=node[j].t;
                    vis[j]=1;
                    Q.push(node[j]);
                }
            }
        }

        printf("%d\n",ans);
    }
    return 0;
}