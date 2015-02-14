//#pragma comment(linker,"/STACK:102400000,102400000")
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
typedef long long ll;

int T, n, L, R;
ll a[20];

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a%b);
}

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

ll dfs(ll x, ll s, ll k)
{
    if (s > x) return 0;
    ll ret = x/s;
    for (int i=k;i<n;i++)
        ret -= dfs(x, lcm(s,a[i]), i+1);
    return ret;
}

ll f(ll x)
{
    ll ret = 0;
    for (int i=0;i<n;i++)
        ret += dfs(x, a[i], i+1);
    return ret;
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &n, &L, &R);
        for (int i=0;i<n;i++) scanf("%lld", &a[i]);
        printf("%lld\n", f(R) - f(L-1));
    }
    return 0;
}
