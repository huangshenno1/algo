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

const int maxn = 15;
int n, s, r, ans;
int a[maxn], b[maxn];

int main()
{
    while (scanf("%d%d%d", &n, &s, &r) == 3)
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for (int i=0;i<s;i++)
        {
            int x;
            scanf("%d", &x);
            a[x]++;
        }
        for (int i=0;i<r;i++)
        {
            int x;
            scanf("%d", &x);
            b[x]++;
            if (a[x]) {a[x] = b[x] = 0;}
        }
        ans = 0;

        for (int i=1;i<=n;i++)
            if (a[i])
            {
                if (b[i-1]) {a[i] = 0; b[i-1] = 0;}
                else if (b[i+1]) {a[i] = 0; b[i+1] = 0;}
                else ans ++;
            }

        printf("%d\n", ans);
    }
    return 0;
}
