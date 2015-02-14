#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 410;

int n, ans, dp[maxn];
int g[maxn][maxn];

struct Node
{
    int num, prize;
    bool operator < (const Node &t) const {return prize < t.prize;}
}node[maxn];

int main()
{
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &node[i].prize);
            node[i].num = i;
            dp[i] = 0;
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &g[i][j]);

        for (int i = 0; i < n; i++)
            if (g[0][i] <= node[i].prize)
                dp[i] = 1;

        sort(node, node+n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (dp[node[j].num] && dp[node[i].num]<=dp[node[j].num] && node[j].prize + g[node[j].num][node[i].num] <= node[i].prize)
                    dp[node[i].num] = dp[node[j].num] + 1;
            }
        }

        ans = 0;
        for (int i = 0; i < n; i++)
            if (ans < dp[i])
                ans = dp[i];
        printf("%d\n", ans);
    }
    return 0;
}