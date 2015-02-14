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

const int maxn = 50005;
int T, n, k;
ll ans, a[maxn], b[maxn], c[maxn];

ll f(ll p)
{
    memcpy(b, a, sizeof(a));
    ll ret = 0;
    ll cc = 0, c1 = 0, c2 = 0, j = n;
    for (int i=n;i>=1;i--)
    {
        while (j > i && (j - i) * (j - i) > p)
        {
            cc -= c[j];
            c1 -= c[j] * j;
            c2 -= c[j] * j * j;
            j--;
        }
        b[i] -= (cc * p - cc * i * i - c2 + c1 * 2 * i);
        if (b[i] < 0) {c[i] = 0; continue;}
        c[i] = b[i] / p + 1;
        ret += c[i];
        if (ret > k) return k + 1;
        cc += c[i];
        c1 += c[i] * i;
        c2 += c[i] * i * i;
    }
    return ret;
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &k);
        for (int i=1;i<=n;i++) scanf("%lld", &a[i]);
        ll low = 1, high = 1LL << 60, mid, ans;
        while (low < high)
        {
            mid = (low + high) / 2;
            if (f(mid) <= k) ans = high = mid;
            else low = mid + 1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
