#include <cstdio>
#include <cstring>
#include <cctype>
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

const int maxn = 5010;
const int maxx = 1000010;
const int INF = 0x3f3f3f3f;
int T,n;
int x[maxn],y[maxn],l[maxn];
int dp[maxx],ans;

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
        for (int i=1;i<=n;i++) l[i]=max(0,x[i]-(int)sqrt(2.0*y[i]*y[1]-1.0*y[1]*y[1]));
        ans=INF;
        memset(dp,0x3f,sizeof(dp));
        dp[x[1]]=0;
        for (int i=2;i<=n;i++)
            for (int j=l[i];j<x[i];j++)
            {
                int t=x[i]*2-j;
                if (t<x[n]) dp[t]=min(dp[t],dp[j]+1);
                else ans=min(ans,dp[j]+1);
            }
        if (ans==INF) ans=-1;
        printf("%d\n",ans);
    }
    return 0;
}
