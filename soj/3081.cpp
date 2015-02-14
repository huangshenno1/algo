#include <cstdio>

const int r = 19871118;

long long pow(long long x, int n)
{
    long long res = 1;
    while (n)
    {
        if (n & 1) res = (res * x) % r;
        x = (x * x) % r;
        n >>= 1;
    }
    return res;
}

int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)==2)
    {
        if (m==1 && n>1)
        {
            printf("0\n");
            continue;
        }
        long long ans = (m * pow(m-1, n-1)) % r;
        printf("%lld\n",ans);
    }
    return 0;
}