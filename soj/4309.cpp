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

#define ll long long
#define pii pair<int, int>
#define fr first
#define sc second
#define mp make_pair
#define FOR(i,j,k) for(int i=j;i<=(k);i++)
#define FORD(i,j,k) for(int i=j;i>=(k);i--)
#define REP(i,n) for(int i=0;i<(n);i++)

ll n;

int main()
{
    while (scanf("%lld", &n) == 1)
    {
        ll k = 4 * (ll)(n / 4);
        ll ans = 0;
        for (ll x=k;x<=n;x++) ans ^= x;
        printf("%lld\n", ans);
    }
    return 0;
}
