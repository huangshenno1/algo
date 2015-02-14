#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cmath>
#include <iostream>
#include <sstream>
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

const int dx[] = {1, 1, -1, -1, 2, 2, -2, -2}, dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
const int maxn = 105;
int r, c, gr, gc, lr, lc;
int dis[maxn][maxn];

inline bool inside(int i, int j)
{
    return i>=1 && i<=r && j>=1 && j<=c;
}

void bfs()
{
    memset(dis, -1, sizeof(dis));
    queue<int> Q;
    dis[gr][gc] = 0;
    Q.push(gr*111+gc);
    while (!Q.empty())
    {
        int rr = Q.front()/111, cc = Q.front()%111; Q.pop();
        for (int d=0;d<8;d++)
        {
            int i = rr+dx[d], j = cc+dy[d];
            if (!inside(i, j)) continue;
            if (dis[i][j] == -1 || dis[i][j] > dis[rr][cc]+1)
            {
                dis[i][j] = dis[rr][cc]+1;
                Q.push(i*111+j);
            }
        }
    }
}

int main()
{
    while (scanf("%d%d%d%d%d%d", &r, &c, &gr, &gc, &lr, &lc) == 6)
    {
        bfs();
        int ans = dis[lr][lc];
        if (ans == -1) puts("impossible");
        else printf("%d\n", ans);
    }
    return 0;
}
