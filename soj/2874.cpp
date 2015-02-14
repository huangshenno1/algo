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

#define ll long long
#define pii pair<int, int>
#define fr first
#define sc second
#define mp make_pair
#define FOR(i,j,k) for(int i=j;i<=(k);i++)
#define FORD(i,j,k) for(int i=j;i>=(k);i--)
#define REP(i,n) for(int i=0;i<(n);i++)

const int di[] = {-1, 0, 1, 0}, dj[] = {0, 1, 0, -1};
const int maxn = 1005;
int n, t, d;
char a[maxn][maxn];
int dp[maxn][maxn];
pii st, ed, cur, nxt;
queue<pii> Q;

inline bool valid(pii cur)
{
    return cur.fr >= 0 && cur.fr < n && cur.sc >= 0 && cur.sc < n && a[cur.fr][cur.sc] != '*';
}

int main()
{
    while (scanf("%d", &n) == 1)
    {
        REP(i, n) scanf("%s", a[i]);
        REP(i, n) REP(j, n)
        {
            if (a[i][j] == 'F') st = mp(i, j);
            if (a[i][j] == 'J') ed = mp(i, j);
        }
        memset(dp, -1, sizeof(dp));
        while (!Q.empty()) Q.pop();
        Q.push(st); dp[st.fr][st.sc] = 0;
        while (!Q.empty())
        {
            cur = Q.front(); Q.pop();
            t = dp[cur.fr][cur.sc];
            REP(r, 4)
            {
                nxt = mp(cur.fr + di[r], cur.sc + dj[r]);
                if (!valid(nxt)) continue;
                if (dp[nxt.fr][nxt.sc] >= 0 && dp[nxt.fr][nxt.sc] <= t + 1) continue;
                Q.push(nxt); dp[nxt.fr][nxt.sc] = t + 1;
            }
        }
        if (dp[ed.fr][ed.sc] == -1) {puts("No solution."); continue;}

        t = 0; d = 0;
        cur = ed;
        bool go = 1;
        while (1)
        {
            if (dp[cur.fr][cur.sc] == t) {go = 0; break;}
            REP(r, 4)
            {
                nxt = mp(cur.fr + di[r], cur.sc + dj[r]);
                if (!valid(nxt)) continue;
                if (dp[nxt.fr][nxt.sc] == t) {go = 0; break;}
            }
            if (!go) break;
            nxt = mp(cur.fr + di[d], cur.sc + dj[d]);
            while (!valid(nxt)) {d++; d %= 4; nxt = mp(cur.fr + di[d], cur.sc + dj[d]);}
            cur = nxt;
            t++;
        }
        printf("%d\n", t);
    }
    return 0;
}
