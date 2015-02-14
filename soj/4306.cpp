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

#define ll long long
#define pii pair<int, int>
#define fr first
#define sc second
#define mp make_pair
#define FOR(i,j,k) for(int i=j;i<=(k);i++)
#define FORD(i,j,k) for(int i=j;i>=(k);i--)
#define REP(i,n) for(int i=0;i<(n);i++)

const int maxn = 100005;
int n, q, l, r;
int a[maxn];
int pre[maxn], dp[maxn];

int main()
{
    while (scanf("%d%d", &n, &q) == 2)
    {
        for (int i=1;i<=n;i++) scanf("%d", &a[i]);
        memset(pre, 0, sizeof(pre));
        dp[0] = 0;
        for (int i=1;i<=n;i++)
        {
            dp[i] = pre[a[i]];
            if (dp[i] < dp[i-1]) dp[i] = dp[i-1];
            pre[a[i]] = i;
        }
        while (q--)
        {
            scanf("%d%d", &l, &r);
            if (dp[r] >= l) puts("No");
            else puts("Yes");
        }
    }
    return 0;
}
