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

const int mod = 1000000007;

ll pow_mod(ll x, int y)
{
    ll ret = 1;
    while (y)
    {
        if (y&1) ret = ret * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ret;
}

int main()
{
    int n;
    while (scanf("%d", &n) == 1)
    {
        printf("%lld\n", (2LL*pow_mod(4LL, n-1)) % mod);
    }
    return 0;
}
