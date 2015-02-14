#include <cstdio>
#include <queue>
using namespace std;

const int maxn = 760;
const int di[] = {0,0,1,-1,1,-1,1,-1};
const int dj[] = {1,-1,0,0,1,-1,-1,1};

int n, m, ans;
char mp[maxn][maxn];
bool vis[maxn][maxn];

bool out(int i, int j)
{
    if (i<=0 || j<=0 || i>n || j>n) return 1;
    return 0;
}

void find(int i, int j)
{
    if (!vis[i][j] && mp[i][j] == '.')
    {
        vis[i][j] = 1;
        int cnt = 1;
        queue<int> Q;
        Q.push(i * 1024 + j);
        while (!Q.empty())
        {
            int temp = Q.front();
            Q.pop();
            i = temp / 1024;
            j = temp % 1024;
            for (int d = 0; d < 8; d++)
            {
                int ni = i + di[d];
                int nj = j + dj[d];
                if (!out(ni, nj) && !vis[ni][nj] && mp[ni][nj] == '.')
                {
                    vis[ni][nj] = 1;
                    cnt++;
                    Q.push(ni * 1024 + nj);
                }
            }
        }
        if (cnt > ans) ans = cnt;
    }    
}

int main()
{
    while (scanf("%d%d", &m, &n) == 2)
    {
        getchar();
        for (int i = 1; i <= n; i++)
            scanf("%s", mp[i]+1);

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                vis[i][j] = 0;

        ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                find(i, j);

        printf("%d\n", ans);
    }
    return 0;
}