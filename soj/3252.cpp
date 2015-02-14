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

const int mod = 10007;
int T, n, m;
int pii[mod+10];

int inv(int x)
{
    int ret = 1, y = mod - 2;
    while (y)
    {
        if (y & 1) ret = (ret * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return ret;
}

int C(int a, int b)
{
    if (a < b) return 0;
    if (b == 0) return 1;
    if (a >= mod) return C(a/mod, b/mod) * C(a%mod, b%mod) % mod;
    int ret = ((pii[a] * inv(pii[a-b])) % mod * inv(pii[b])) % mod;
    return ret;
}

int main()
{
    pii[0] = 1;
    for (int i = 1; i < mod; i++) pii[i] = (pii[i-1] * i) % mod;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        printf("%d\n", C(n, m));
    }
    return 0;
}
