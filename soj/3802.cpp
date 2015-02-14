#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cmath>
#include <cassert>
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

int xx, T;
ll n, k, p, a, b;

int main()
{
    while (scanf("%d", &xx) == 1)
    {
        scanf("%d", &T);
        if (xx == 0)
            while (T--)
            {
                scanf("%lld%lld%lld", &n, &k, &p);
                a = 0;
                for (int t=1;t<=n;t++)
                {
                    ll c = p/(2*k), r = p%(2*k);
                    if (r < k)
                    {
                        a <<= 1;
                        a |= 0;
                        p = c*k + r;
                    }
                    else
                    {
                        a <<= 1;
                        a |= 1;
                        p = c*k + r - k;
                    }
                    b = p;
                }
                printf("%lld %lld %lld %lld\n", n, k, a, b);
            }
        else
            while (T--)
            {
                scanf("%lld%lld%lld%lld", &n, &k, &a, &b);
                for (int t=1;t<=n;t++)
                {
                    ll c = b/k, r = b%k;
                    if (a&1)
                    {
                        b = c*k*2 + k + r;
                    }
                    else
                    {
                        b = c*k*2 + r;
                    }
                    a >>= 1;
                }
                p = b;
                printf("%lld %lld %lld\n", n, k, p);
            }
    }
    return 0;
}
