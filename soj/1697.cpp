#include <iostream>
#include <string.h>
using namespace std;

const int N = 24;
const int NN = 100;
const int Inf = 0x7fffffff;

struct Edge
{
    int u,v,t;
    Edge(int a=0,int b=0,int c=0):u(a),v(b),t(c){}
}edge[NN];

int R[N+1],T[N+1],Mincost[N+1];
int num;

void BuildMap()
{
    for(int i=1;i<=N;++i)    edge[num++] = Edge(i,i-1,0);
    for(int i=1;i<=N;++i)    edge[num++] = Edge(i-1,i,T[i-1]);
    for(int i=1;i+8<=N;++i) edge[num++] = Edge(i+8,i,-R[i+8-1]);
}


inline bool Relaxed(int i)
{
    if(Mincost[edge[i].u] != Inf && Mincost[edge[i].v] > Mincost[edge[i].u]+edge[i].t)
    {
        Mincost[edge[i].v] = Mincost[edge[i].u]+edge[i].t;
        return true;
    }
    return false;
}

bool Bellman_Ford(int m)
{
    int k = 0;
    for(int i=17;i<=N;++i) edge[num+k] = Edge(i+8-24,i,m-R[i+8-24-1]),++k;
    edge[num+k] = Edge(24,0,-m),++k;
    for(int i=1;i<=N;++i) Mincost[i] = Inf;
    Mincost[0] = 0;
    for(int v=0;v<N;++v)
    {
        bool relaxed = false;
        for(int i=0;i<num+k;++i)
        {
            if(Relaxed(i)) relaxed = true;
        }
        if(!relaxed) return true;
    }
    for(int i=0;i<num+k;++i) if(Relaxed(i)) return false;
    return true;
}

int main()
{
    int n,m,t;
    scanf("%d",&t);
    while(t--)
    {
        for(int i=0;i<N;++i) scanf("%d",&R[i]);
        scanf("%d",&n);
        memset(T,0,sizeof(0));
        for(int i=0;i<n;++i) scanf("%d",&m),++T[m];
        num = 0;
        BuildMap();
        if(!Bellman_Ford(n)) printf("No Solution\n");
        else
        {
            int ans = n;
            int l = 0,r = n;
            while(l <= r)
            {
                int mid = (l+r)/2;
                if(Bellman_Ford(mid)) r = mid-1,ans = mid;
                else                  l = mid+1;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}