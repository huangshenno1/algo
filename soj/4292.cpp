#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 100010;
int a,b;
int dp[maxn];
queue<int> Q;

int main()
{
    while (scanf("%d%d",&a,&b)==2)
    {
        if (a>b) {puts("-1"); continue;}
        memset(dp,0x3f,sizeof(dp));
        while (!Q.empty()) Q.pop();
        dp[a]=0; Q.push(a);
        while (!Q.empty())
        {
            int x=Q.front(); Q.pop();
            if (x==b) break;
            int xx=(int)(sqrt(x+1.0));
            for (int i=1;i<=xx;i++)
                if (x%i==0)
                {
                    if (x+i<=b && dp[x+i]>dp[x]+1) {dp[x+i]=dp[x]+1; Q.push(x+i);}
                    if (x+x/i<=b && dp[x+x/i]>dp[x]+1) {dp[x+x/i]=dp[x]+1; Q.push(x+x/i);}
                }
        }
        printf("%d\n",dp[b]);
    }
    return 0;
}
