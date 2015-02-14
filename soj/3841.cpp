#include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;

#define FOR(i,j,k) for(int i=j;i<=(k);i++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define ll long long
#define inf (int)1e9
#define base 102
#define maxn 55
#define pii pair<int,int>
#define fr first
#define sc second

int s[128];
int n, m;
char mp[maxn][maxn];
int dp[maxn];
int ans[5];

int main()
{
    s['.'] = 0; s['#'] = -10; s['X'] = 1;
    while (scanf("%d%d", &n, &m) == 2)
    {
        for (int i=1;i<=n;i++)
            scanf("%s", mp[i]+1);
        memset(ans, 0, sizeof(ans));
        for (int j=1;j<m;j++)
        {
            dp[j] = s[mp[1][j]] + s[mp[2][j]] + s[mp[1][j+1]] + s[mp[2][j+1]];
            if (dp[j] >= 0) ans[dp[j]]++;
        }
        for (int i=3;i<=n;i++)
            for (int j=1;j<m;j++)
            {
                dp[j] += s[mp[i][j]] + s[mp[i][j+1]] - s[mp[i-2][j]] - s[mp[i-2][j+1]];
                if (dp[j] >= 0) ans[dp[j]]++;
            }
        for (int i=0;i<5;i++) printf("%d\n", ans[i]);
    }
    return 0;
}
