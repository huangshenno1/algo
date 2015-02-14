#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N;
bool cannum[10], canop[5];
int dp[1000][1000][5][2], ans;
queue<int> Q;

int getopid(char ch)
{
    if (ch == '+') return 1;
    if (ch == '-') return 2;
    if (ch == '*') return 3;
    if (ch == '/') return 4;
    return 0;
}

inline int getid(int disp, int val, int op, int stt)
{
    return disp*10000 + val*10 + op*2 + stt;
}

void splitid(int x, int &disp, int &val, int &op, int &stt)
{
    disp = x/10000; x %= 10000;
    val = x/10; x %= 10;
    op = x/2; stt = x&1;
}

inline bool valid(int x)
{
    return x >= 0 && x < 1000;
}

int eval(int disp, int val, int op)
{
    int ret;
    if (op == 1) ret = val + disp;
    if (op == 2) ret = val - disp;
    if (op == 3) ret = val * disp;
    if (op == 4)
    {
        if (disp == 0) return -1;
        ret = val / disp;
    }
    if (valid(ret)) return ret;
    return -1;
}

void solve()
{
    memset(dp, 0x3f, sizeof(dp));
    while (!Q.empty()) Q.pop();
    for (int i=0;i<10;i++)
        if (cannum[i])
        {
            dp[i][0][0][0] = 1;
            Q.push(getid(i, 0, 0, 0));
        }
    for (int i=0;i<5;i++)
        if (canop[i])
        {
            dp[0][0][i][1] = 1;
            Q.push(getid(0, 0, i, 1));
        }

    while (!Q.empty())
    {
        int top = Q.front(); Q.pop();
        int disp, val, op, stt;
        splitid(top, disp, val, op, stt);
        //printf("%d %d %d %d %d\n", disp, val, op, stt, dp[disp][val][op][stt]);
        if (disp == N) return;
        if (stt == 0)
        {
            for (int i=0;i<10;i++)
                if (cannum[i])
                {
                    int ndisp = disp * 10 + i;
                    if (ndisp >= 1000) continue;
                    if (dp[ndisp][val][op][0] > dp[disp][val][op][0] + 1)
                    {
                        dp[ndisp][val][op][0] = dp[disp][val][op][0] + 1;
                        Q.push(getid(ndisp, val, op, 0));
                    }
                }
            for (int i=0;i<5;i++)
                if (canop[i])
                {
                    int ndisp = disp;
                    if (op > 0)
                    {
                        ndisp = eval(disp, val, op);
                        if (ndisp == -1) continue;
                    }
                    if (dp[ndisp][ndisp][i][1] > dp[disp][val][op][0] + 1)
                    {
                        dp[ndisp][ndisp][i][1] = dp[disp][val][op][0] + 1;
                        Q.push(getid(ndisp, ndisp, i, 1));
                    }
                }
        }
        else
        {
            for (int i=0;i<10;i++)
                if (cannum[i])
                {
                    int ndisp = i;
                    if (dp[ndisp][val][op][0] > dp[disp][val][op][1] + 1)
                    {
                        dp[ndisp][val][op][0] = dp[disp][val][op][1] + 1;
                        Q.push(getid(ndisp, val, op, 0));
                    }
                }
            for (int i=0;i<5;i++)
                if (canop[i])
                {
                    int ndisp = disp;
                    if (i == 0 && op > 0)
                    {
                        ndisp = eval(disp, val, op);
                        if (ndisp == -1) continue;
                    }
                    if (dp[ndisp][ndisp][i][1] > dp[disp][val][op][1] + 1)
                    {
                        dp[ndisp][ndisp][i][1] = dp[disp][val][op][1] + 1;
                        Q.push(getid(ndisp, ndisp, i, 1));
                    }
                }
        }
    }
}

int main()
{
    char tmp[20];
    while (scanf("%s%d", tmp, &N) == 2)
    {
        if (N == 0) {puts("0"); continue;}
        memset(cannum, 0, sizeof(cannum));
        memset(canop, 0, sizeof(canop));
        for (int i=0;tmp[i];i++)
        {
            if (tmp[i] >= '0' && tmp[i] <= '9') cannum[tmp[i]-'0'] = 1;
            else canop[getopid(tmp[i])] = 1;
        }
        solve();
        ans = 0x3f3f3f3f;
        for (int i=0;i<1000;i++)
            for (int j=0;j<5;j++)
                ans = min(ans, min(dp[N][i][j][0], dp[N][i][j][1]));
        if (ans == 0x3f3f3f3f) puts("impossible");
        else printf("%d\n", ans);
    }
    return 0;
}
