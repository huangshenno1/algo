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

const int maxn = 1005;
int a[maxn][maxn], dp[maxn][maxn];

inline int max(int a, int b) {return a > b ? a : b;}

int main()
{
    int T, cas = 1, n, m;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n ,&m);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                scanf("%d", &a[i][j]);
        memset(dp, 0, sizeof(dp));
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + a[i][j];
        printf("Scenario #%d:\n", cas++);
        printf("%d\n\n", dp[n][m]);
    }
    return 0;
}
