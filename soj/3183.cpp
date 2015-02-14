#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 25;
const int maxnn = 1100000;
int T,n;
int dp[maxnn];
int w[maxn],base[maxn];
int ans[maxn],ans1;
int cc[maxn];

void dfs(int state, int h, int sum)
{
    dp[state]=sum;
    if (h==n)
    {
        if (sum<ans1)
        {
            ans1=sum;
            for (int i=0;i<n;i++)
                ans[i]=cc[i];
        }
        return;
    }
    for (int i=0;i<n;i++)
    {
        if (!(state&1<<i) && (base[i]&state)==base[i])
        {
            int tmp=sum+h*w[i];
            if (tmp>=dp[state|1<<i]) continue;
            cc[h]=i;
            dfs(state|1<<i,h+1,sum+h*w[i]);
        }
    }
}

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        for (int i=0;i<n;i++) scanf("%d",&w[i]);
        for (int i=0;i<n;i++)
        {
            base[i]=0;
            for (int j=0;j<n;j++)
            {
                int tmp;
                scanf("%d",&tmp);
                if (tmp) base[i]|=1<<j;
            }
        }
        memset(dp,0x3f,sizeof(dp));
        ans1=INF;
        dfs(0,0,0);
        if (ans1>=INF) {printf("-1\n-1\n"); continue;}
        printf("%d\n",ans1);
        for (int i=0;i<n;i++) printf("%d ",ans[i]);
        puts("");
    }
    return 0;
}
