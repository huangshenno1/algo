#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 205;
int T,n,m,a,b;
int in[maxn];
vector<int> pre[maxn];
priority_queue<int> Q;
int ans[maxn],cnt;

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&m);
        memset(in,0,sizeof(in));
        for (int i=1;i<=n;i++) pre[i].clear();
        while (m--)
        {
            scanf("%d%d",&a,&b);
            pre[b].push_back(a);
            in[a]++;
        }

        while (!Q.empty()) Q.pop();
        for (int i=1;i<=n;i++)
            if (in[i]==0) Q.push(i);
        cnt=n;

        while (!Q.empty())
        {
            int t=Q.top(); Q.pop();
            ans[t]=cnt--;
            for (int i=0;i<pre[t].size();i++)
                if (--in[pre[t][i]]==0) Q.push(pre[t][i]);
        }

        if (cnt==0)
        {
            for (int i=1;i<n;i++) printf("%d ",ans[i]);
            printf("%d\n",ans[n]);
        }
        else puts("-1");
        printf("\n");
    }
    return 0;
}