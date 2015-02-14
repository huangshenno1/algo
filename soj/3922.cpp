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

const int maxn = 200010;
int n, a[maxn];
int ans1, ans2, s, x;

int main()
{
    while (scanf("%d", &n) == 1)
    {
        n = n * 2 + 2;
        s = 0;
        REP(i, n)
        {
            scanf("%d", &a[i]);
            s ^= a[i];
        }
        x = 1;
        while (!(s & x)) x <<= 1;
        ans1 = ans2 = 0;
        REP(i, n)
        {
            if (x & a[i]) ans1 ^= a[i];
            else ans2 ^= a[i];
        }
        if (ans1 > ans2) swap(ans1, ans2);
        printf("%d %d\n", ans1, ans2);
    }
    return 0;
}
