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
typedef long long ll;

const int INF = 10000;
const int maxn = 30;
int T, n, k, m, un = 26, vn = 26, ans;
int g[maxn][maxn];
int linker[maxn], lu[maxn], lv[maxn], slack[maxn];
bool visu[maxn], visv[maxn];
int a[10005], b[10005];
char ch[2];

bool dfs(int u)
{
    visu[u] = 1;
    for (int v = 0; v < vn; v++)
    {
        if (visv[v]) continue;
        int t = lu[u] + lv[v] - g[u][v];
        if (t == 0)
        {
            visv[v] = 1;
            if (linker[v] == -1 || dfs(linker[v]))
            {
                linker[v] = u;
                return 1;
            }
        }
        else if (slack[v] > t)
            slack[v] = t;
    }
    return 0;
}

int KM()
{
    memset(linker, -1, sizeof(linker));
    memset(lv, 0, sizeof(lv));
    for (int u = 0; u < un; u++) lu[u] = -INF;
    for (int u = 0; u < un; u++)
        for (int v = 0; v < vn; v++)
            if (g[u][v] > lu[u]) lu[u] = g[u][v];

    for (int u = 0; u < un; u++)
    {
        for (int v = 0; v < vn; v++) slack[v] = INF;
        while (1)
        {
            memset(visu, 0, sizeof(visu));
            memset(visv, 0, sizeof(visv));
            if (dfs(u)) break;
            int d = INF;
            for (int v = 0; v < vn; v++)
                if (!visv[v] && d>slack[v])
                    d = slack[v];
            for (int i = 0; i < un; i++)
                if (visu[i]) lu[i] -= d;
            for (int v = 0; v < vn; v++)
                if (visv[v]) lv[v] += d;
                else slack[v] -= d;
        }
    }
    int res = 0;
    for (int v = 0; v < vn; v++)
        if (linker[v] > -1)
            res += g[linker[v]][v];
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &n, &k, &m);
        for (int i=0;i<n;i++)
        {
            scanf("%s", ch);
            a[i] = ch[0] - 'A';
        }
        while (m--)
        {
            memset(g, 0, sizeof(g));
            for (int i=0;i<n;i++)
            {
                scanf("%s", ch);
                b[i] = ch[0] - 'A';
                g[a[i]][b[i]]++;
            }
            ans = KM();
            printf("%.4lf\n", (double)ans / n);
        }
    }
    return 0;
}
