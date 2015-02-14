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

const int maxn = 55;
const int dx[] = {1, 1, 1, -1, -1, -1, 0, 0}, dy[] = {1, 0, -1, 1, 0, -1, 1, -1};
int n;
char mp[maxn][maxn];
int h[maxn][maxn];
int height[maxn*maxn], hc;
bool vis[maxn][maxn];
int px, py, kcnt, hmin, hmax, kmin, kmax;

inline bool can(int i, int j, int a, int b)
{
    return i>=1 && i<=n && j>=1 && j<=n && !vis[i][j] && h[i][j]>=a && h[i][j]<=b;
}

bool check(int a, int b)
{
    memset(vis, 0, sizeof(vis));
    vis[px][py] = 1;
    int cnt = 1;
    queue<int> q;
    while (!q.empty()) q.pop();
    q.push(px<<6|py);
    while (!q.empty())
    {
        int top = q.front(); q.pop();
        int x = top>>6, y = top&63;
        for (int r=0;r<8;r++)
        {
            int nx = x+dx[r], ny = y+dy[r];
            if (!can(nx, ny, a, b)) continue;
            vis[nx][ny] = 1;
            if (mp[nx][ny] == 'K') {cnt++; if (cnt == kcnt) return 1;}
            q.push(nx<<6|ny);
        }
    }
    if (cnt == kcnt) return 1;
    return 0;
}

int main()
{
    while (scanf("%d", &n) == 1)
    {
        for (int i=1;i<=n;i++) scanf("%s", mp[i]+1);
        hc = 0; kcnt = 0;
        hmin = 1<<30; hmax = 0;
        kmin = 1<<30; kmax = 0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
            {
                scanf("%d", &h[i][j]);
                height[hc++] = h[i][j];
                if (mp[i][j] == 'P') {px = i; py = j;}
                if (mp[i][j] == 'P' || mp[i][j] == 'K') {kcnt++; kmin = min(kmin, h[i][j]); kmax = max(kmax, h[i][j]);}
                hmin = min(hmin, h[i][j]); hmax = max(hmax, h[i][j]);
            }

        if (hmax == hmin) {puts("0"); continue;}

        sort(height, height+hc);
        hc = unique(height, height+hc) - height;
        int ans = hmax - hmin;
        int k1, k2;
        for (int i=0;i<hc;i++)
        {
            if (height[i] == kmin) k1 = i;
            if (height[i] == kmax) k2 = i;
        }
        for (int i=0;i<=k1;i++)
        {
            int a = height[i], b;
            int low = k2, high = hc-1, mid;
            while (low <= high)
            {
                mid = (low + high) >> 1;
                b = height[mid];
                if (check(a, b))
                {
                    ans = min(ans, b-a);
                    high = mid - 1;
                }
                else low = mid + 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
