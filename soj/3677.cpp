#include <cstdio>

unsigned long long pow_mod(unsigned long long x, unsigned long long n, unsigned long long mod)
{
    unsigned long long res = 1;
    x = x % mod;
    while (n)
    {
        if (n & 1) res = (res * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}

unsigned long long gcd(unsigned long long a, unsigned long long b)
{
    return b == 0 ? a : gcd(b, a%b);
}

int main()
{
    unsigned long long p, e, k, r;
    while (~scanf("%llu%llu%llu", &p, &e, &k))
    {
        e = (p-1) / gcd(e, p-1);
        while (k--)
        {
            scanf("%llu",&r);
            if (pow_mod(r, e, p) == 1) puts("TAK");
            else puts("NIE");
        }
    }
    return 0;
}