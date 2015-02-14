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

const int mod = (int)1e9 + 7;

int main()
{
    long long sum[4];
    int n;
    while (scanf("%d", &n) == 1)
    {
        memset(sum, 0, sizeof(sum));
        for (int i = 0; i < n; ++ i)
        {
            int a;
            scanf("%d", &a);
            (sum[1] += a) %= mod;
            (sum[2] += (long long)a * a % mod) %= mod;
            (sum[3] += (long long)a * a % mod * a % mod) %= mod;
        }
        printf("%d\n", (int)((((long long)sum[1] * sum[1] % mod * sum[1] % mod - 3LL * sum[1] % mod * sum[2] % mod + 2LL * sum[3] % mod) % mod + mod) % mod));
    }
    return 0;
}
