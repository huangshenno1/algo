#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <climits>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#define FOR(i,j,k) for(int i=j;i<=(k);i++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define ll long long

const int maxn = 205;
int n, m;
int c[maxn], u[maxn], s[maxn], e[maxn], w[maxn], level[maxn];

int main()
{
    while (scanf("%d%d", &n, &m) == 2)
    {
        for (int i=1;i<=n;i++) scanf("%d%d", &c[i], &u[i]);
        memset(level, 0, sizeof(level));
        for (int i=1;i<=m;i++)
        {
            scanf("%d%d%d", &s[i], &e[i], &w[i]);
            level[e[i]] = level[s[i]] + 1;
        }
        int dep = level[e[m]];
        for (int i=1;i<=n;i++)
        {
            if (level[i] == 0) continue;
            for (int j=1;j<=m;j++)
                if (e[j] == i && c[s[j]] > 0)
                    c[i] += c[s[j]] * w[j];
            c[i] -= u[i];
        }
        bool go = 0;
        for (int i=1;i<=n;i++)
            if (level[i] == dep && c[i] > 0)
            {
                go = 1;
                printf("%d %d\n", i, c[i]);
            }
        if (!go) puts("NULL");
    }
    return 0;
}
