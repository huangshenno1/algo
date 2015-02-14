#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cmath>
#include <cassert>
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

#define ll long long
#define pii pair<int, int>
#define fr first
#define sc second
#define mp make_pair
#define FOR(i,j,k) for(int i=j;i<=(k);i++)
#define FORD(i,j,k) for(int i=j;i>=(k);i--)
#define REP(i,n) for(int i=0;i<(n);i++)

const int maxn = 100005;
int n, a[maxn];
int dp[2][32][2];

int main()
{
    while (scanf("%d", &n) == 1)
    {
        for (int i=1;i<=n;i++) scanf("%d", &a[i]);
        bool flag = 0;
        memset(dp[flag], 0, sizeof(dp[flag]));
        ll ans = 0;
        for (int i=1;i<=n;i++)
        {
            flag ^= 1;
            memset(dp[flag], 0, sizeof(dp[flag]));
            for (int j=0;j<32;j++)
                for (int k=0;k<2;k++)
                {
                    if ((a[i]>>j)&1) dp[flag][j][k^1] += dp[flag^1][j][k];
                    else dp[flag][j][k] += dp[flag^1][j][k];
                }
            for (int j=0;j<32;j++)
                dp[flag][j][(a[i]>>j)&1]++;
            for (int j=0;j<32;j++)
                ans += (ll)dp[flag][j][1] << j;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
