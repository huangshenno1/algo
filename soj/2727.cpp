#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 200001;
int f[maxn];
int a,b;
queue<int> Q;

void solve()
{
    memset(f,-1,sizeof(f));
    f[a]=0;
    while (!Q.empty()) Q.pop();
    Q.push(a);
    while (!Q.empty())
    {
        int x=Q.front(); Q.pop();
        if (x-1>=0 && f[x-1]==-1)
        {
            f[x-1]=f[x]+1;
            if (x-1==b) return;
            Q.push(x-1);
        }
        if (x+1<2*b && f[x+1]==-1)
        {
            f[x+1]=f[x]+1;
            if (x+1==b) return;
            Q.push(x+1);
        }
        if (x*2<2*b && f[x*2]==-1)
        {
            f[x*2]=f[x]+1;
            if (x*2==b) return;
            Q.push(x*2);
        }
    }
}

int main()
{
    while (scanf("%d%d",&a,&b)==2)
    {
        solve();
        printf("%d\n",f[b]);
    }
    return 0;
}