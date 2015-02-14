#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int n;
int a, b;
int ans[40], d;
ll powa[40];

void solve()
{
    if (a < 0)
    {
        puts("IMPOSSIBLE");
        return;
    }
    if (a == 0)
    {
        if (b == 0) puts("0");
        else puts("IMPOSSIBLE");
        return;
    }
    if (a > b)
    {
        puts("IMPOSSIBLE");
        return;
    }
    if (a == b)
    {
        if (a == 1) puts("AMBIGUOUS");
        else printf("%d\n", a);
        return;
    }
    if (a == 1 && a < b)
    {
        puts("IMPOSSIBLE");
        return;
    }

    d = (int)(log(b)/log(a));
    powa[0] = 1;
    for (int i=1;i<=d;i++) powa[i] = powa[i-1] * a;
    memset(ans, 0, sizeof(ans));
    ll x = powa[d] * a;
    ans[d] = a;

    for (int i=d;i>0&&x>b;i--)
    {
        ll c = (x-b) / (powa[i] - powa[i-1]);
        c = min(c, (ll)ans[i]);
        x -= (powa[i] - powa[i-1]) * c;
        ans[i] -= c; ans[i-1] += c;
    }
    if (x != b)
    {
        puts("IMPOSSIBLE");
        return;
    }

    for (int i=d;i>0;i--) printf("%d ", ans[i]);
    printf("%d\n", ans[0]);
}

int main()
{
    while (scanf("%d", &n) == 1)
    {
        while (n--)
        {
            scanf("%d%d", &a, &b);
            solve();
        }
    }
    return 0;
}
