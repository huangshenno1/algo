#include <cstdio>
#include <cstring>

typedef long long ll;
const int mod = 100003;

ll pow_mod(ll x, ll y)
{
    ll ret = 1;
    while (y)
    {
        if (y&1) ret = ret*x%mod;
        x = x*x%mod;
        y >>= 1;
    }
    return ret;
}

int main()
{
    int T;
    int n, m;
    ll ans;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        ans = (pow_mod(m, n) - (m * pow_mod(m-1, n-1)) % mod + mod) % mod;
        printf("%d\n", (int)ans);
    }
    return 0;
}