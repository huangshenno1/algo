#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
using namespace std;

typedef long long ll;
const int maxn = 1010;
int T,n;
bool vis[maxn];
int p[maxn],pp;
ll dp[maxn];

int main()
{
    memset(vis,0,sizeof(vis));
    for (int i=2;i<=1009;i++)
        for (int j=i*i;j<=1009;j+=i)
            vis[j]=1;
    pp=0;
    for (int i=2;i<=1009;i++)
        if (!vis[i]) p[pp++]=i;
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for (int i=0;p[i]<=1000;i++)
        for (int j=p[i];j<=1000;j++)
            dp[j]+=dp[j-p[i]];
    for (int i=0;p[i]<=1000;i++)
        dp[p[i]]--;
    dp[0]=0;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        printf("%lld\n",dp[n]);
    }
    return 0;
}
