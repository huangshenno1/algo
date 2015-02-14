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
int n, ans;
int a[maxn];
int b[maxn], dp[maxn];

int main()
{
    while (scanf("%d", &n) == 1)
    {
        for (int i=1;i<=n;i++) scanf("%d", &a[i]), a[i] -= i;
        memset(b, 0x3f, sizeof(b));
        memset(dp, 0, sizeof(dp));
        ans = 0;
        for (int i=1;i<=n;i++)
        {
            int k = upper_bound(b+1, b+n+1, a[i]) - b;
            dp[i] = k;
            b[k] = a[i];
            ans = max(ans, dp[i]);
        }
        printf("%d\n", n - ans);
    }
    return 0;
}
