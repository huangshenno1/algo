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

int n, k, r, c, c1, c2;
vector<int> R, C;

int main()
{
    while (scanf("%d%d", &n, &k) == 2)
    {
        R.clear(); C.clear();
        c1 = c2 = 0;
        REP(i, k)
        {
            scanf("%d%d", &r, &c);
            R.push_back(r);
            C.push_back(c);
        }
        sort(R.begin(), R.end()); sort(C.begin(), C.end());
        c1 = unique(R.begin(), R.end()) - R.begin();
        c2 = unique(C.begin(), C.end()) - C.begin();
        ll ans = (ll)c1 * n + (ll)c2 * n - (ll)c1 * c2;
        printf("%lld\n", ans);
    }
    return 0;
}
