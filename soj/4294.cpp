#include <cstdio>
#include <cstring>

typedef long long ll;
const int maxn = 20;
int n,mod;
ll a[maxn][maxn];
ll dp[1<<maxn];

ll dfs(int x,int k)
{
    if (dp[x]) return dp[x];
    ll res=0;
    for (int i=0;i<n;i++)
        if (x&1<<i)
            res=(res+dfs(x&(~(1<<i)),k-1)*a[k-1][i])%mod;
    return dp[x]=res;
}

int main()
{
    while (scanf("%d%d",&n,&mod)==2)
    {
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                scanf("%lld",&a[i][j]);
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        printf("%lld\n",dfs((1<<n)-1,n));
    }
    return 0;
}
