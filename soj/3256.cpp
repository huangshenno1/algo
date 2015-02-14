#include <cstdio>
#include <cmath>
typedef long long ll;
const int mod = 20080913;
int T, n, ans;

ll pow2(int y)
{
    ll ret = 1, x = 2;
    while (y)
    {
        if (y & 1) ret = ret * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ret;
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        ans = (12 * pow2(n-1) - 7 + mod) % mod;
        printf("%d\n", ans);
    }
    return 0;
}
