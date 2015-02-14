#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

#define INF 0xfffffff
#define MAX_N 5010

int n,nn;
vector<int> edge[MAX_N];
bool vis[MAX_N];
int dfn[MAX_N],idex;
int low[MAX_N];
int idx[MAX_N];
int stack[MAX_N],top;
bool instack[MAX_N];
vector<int> current[MAX_N];
int hasH[MAX_N];
int cost[MAX_N],newcost[MAX_N];
int indexx[MAX_N];

int Min(int a,int b)
{
    return a<b?a:b;
}

void DFS(int u)
{
    vis[u]=1;
    dfn[u]=low[u]=idex++;
    instack[u]=1;
    stack[++top]=u;
    for (int i=0;i<edge[u].size();i++)
    {
        int v=edge[u][i];
        if (!vis[v])
        {
            DFS(v);
            low[u]=Min(low[u],low[v]);
        }
        else if (instack[v])
        {
            low[u]=Min(low[u],dfn[v]);
        }
    }
    if (dfn[u]==low[u])
    {
        int v=-1;
        while (u!=v)
        {
            v=stack[top--];
            instack[v]=0;
            idx[v]=nn;
        }
        current[nn++].clear();
    }
}

void Tarjan()
{
    memset(vis,0,sizeof(vis));
    idex=0;
    top=0;
    nn=0;
    for (int i=0;i<n;i++)
    {
        if (!vis[i])
            DFS(i);
    }
    memset(hasH,-1,sizeof(hasH));
    for (int u=0;u<n;u++)
    {
        for (int i=0;i<edge[u].size();i++)
        {
            int v=edge[u][i];
            if (idx[u]!=idx[v] && hasH[idx[u]]!=idx[v])
            {
                hasH[idx[u]]=idx[v];
                current[idx[u]].push_back(idx[v]);
            }
        }
    }
}

int main()
{
    int m,id,cc,a,b;
    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=0;i<n;i++)
            edge[i].clear();
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&id,&cc);
            cost[id-1]=cc;
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            edge[a-1].push_back(b-1);
        }

        Tarjan();

        for(int i=0;i<nn;i++)
            newcost[i]=INF;
        for(int i=0;i<n;i++)
        {
            newcost[idx[i]]=min(newcost[idx[i]],cost[i]);
        }
        memset(indexx,0,sizeof(indexx));
        for(int i=0;i<nn;i++)
        {
            for(int j=0;j<current[i].size();j++)
            {
                int x=current[i][j];
                indexx[x]++;
            }
        }
        int ret=0;
        for(int i=0;i<nn;i++)
        {
            if(indexx[i]==0) ret+=newcost[i];
        }
        printf("%d\n",ret);
    }
    return 0;
}