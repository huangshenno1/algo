#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;

int T;
ll dp[20][20][4000];
int a[20];

ll f(int cur, int k, int w, bool less)
{
    if (cur == -1)
    {
        if (w == 2000) return 1;
        return 0;
    }
    ll ret = 0;
    if (less)
    {
        if (dp[cur+1][k][w] != -1) return dp[cur+1][k][w];
        for (int i=0;i<10;i++) ret += f(cur-1, k, w+(cur-k)*i, 1);
        return dp[cur+1][k][w] = ret;
    }
    ret = f(cur-1, k, w+(cur-k)*a[cur], 0);
    for (int i=0;i<a[cur];i++) ret += f(cur-1, k, w+(cur-k)*i, 1);
    return ret;
}

ll solve(ll x)
{
    if (x < 0) return 0;
    int l = 0;
    while (x)
    {
        a[l++] = x % 10;
        x /= 10;
    }
    ll ret = 0;
    for (int i=0;i<l;i++)
        ret += f(l-1, i, 2000, 0);
    return ret - l + 1;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    ll x, y, ans;
    cin >> T;
    while (T--)
    {
        cin >> x >> y;
        ans = solve(y) - solve(x-1);
        cout << ans << endl;
    }
    return 0;
}
