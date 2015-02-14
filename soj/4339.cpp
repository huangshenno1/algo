#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn = 1000005;
struct Edge
{
    int u, v, dis;
    Edge(int u=0, int v=0, int dis=0) : u(u), v(v), dis(dis) {}
    bool operator < (const Edge & e) const {return dis < e.dis;}
}a[maxn];
int n, m;

int fa[maxn];

int getfa(int x)
{
    if (fa[x] == -1) return x;
    return fa[x] = getfa(fa[x]);
}

void link(int x, int y)
{
    x = getfa(x); y = getfa(y);
    if (x == y) return;
    fa[y] = x;
}

bool check(int D)
{
    memset(fa, -1, sizeof(fa));
    for (int i=0;i<m;i++)
    {
        if (a[i].dis > D) break;
        link(a[i].u, a[i].v);
    }
    int fa0 = getfa(0);
    for (int i=1;i<n;i++)
        if (getfa(i) != fa0) return 0;
    return 1;
}

int main()
{
    while (scanf("%d%d", &n, &m) == 2 && (n||m))
    {
        int low = -1, high = 0, mid;
        for (int i=0;i<m;i++)
        {
            int u, v, d;
            scanf("%d%d%d", &u, &v, &d);
            a[i] = Edge(u, v, d);
            high = max(high, d);
        }
        sort(a, a+m);
        int ans = -1;
        while (low <= high)
        {
            mid = (low + high) >> 1;
            if (check(mid))
            {
                if (ans == -1 || ans > mid) ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        if (ans < 0) puts("IMPOSSIBLE");
        else printf("%d\n", ans);
    }
    return 0;
}
