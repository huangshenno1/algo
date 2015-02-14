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

const int maxnn = 15;
const int maxn = 105;
const int di[] = {0, 0, 1, -1}, dj[] = {1, -1, 0, 0};
typedef double Matrix[maxn][maxn];
int T, n, m, st, ed;
char plat[maxnn][maxnn];
int d[maxn];
Matrix a;
bool vis[maxnn][maxnn];

inline bool inside(int i, int j)
{
    return i >= 0 && j >= 0 && i < n && j < m;
}

void dfs(int i, int j)
{
    for (int r=0;r<4;r++)
    {
        int ni = i+di[r], nj = j+dj[r];
        if (!inside(ni, nj) || plat[ni][nj] == '#') continue;
        if (!vis[ni][nj])
        {
            vis[ni][nj] = 1;
            dfs(ni, nj);
        }
    }
}

void Gauss_Elimination(Matrix A, int n)
{
    int i, j, k, r;
    for (i = 0; i < n; i++)
    {
        r = i;
        for (j = i+1; j < n; j++)
            if (fabs(A[j][i]) > fabs(A[r][i])) r = j;
        if (r != i) for (j = 0; j <= n; j++) swap(A[r][j], A[i][j]);
        for (k = i+1; k < n; k++)
        {
            double f = A[k][i] / A[i][i];
            for (j = i; j <=n; j++) A[k][j] -= f * A[i][j];
        }
    }
    for (i = n-1; i >= 0; i--)
    {
        for (j = i+1; j < n; j++)
            A[i][n] -= A[j][n] * A[i][j];
        A[i][n] /= A[i][i];
    }
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (int i=0;i<n;i++) scanf("%s", plat[i]);

        memset(vis, 0, sizeof(vis));
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
            {
                if (plat[i][j] == 'A') st = i * m + j;
                if (plat[i][j] == 'B') ed = i * m + j;
            }
        vis[st/m][st%m] = 1;
        dfs(st/m, st%m);
        if (!vis[ed/m][ed%m])
        {
            puts("-1");
            continue;
        }

        memset(d, 0, sizeof(d));
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
            {
                if (!vis[i][j]) continue;
                int id = i * m + j;
                for (int r=0;r<4;r++)
                {
                    int ni = i+di[r], nj = j+dj[r];
                    if (!inside(ni, nj) || plat[ni][nj] == '#') continue;
                    d[id]++;
                }
            }

        memset(a, 0, sizeof(a));
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
            {
                int id = i * m + j;
                if (!vis[i][j] || plat[i][j] == 'B')
                {
                    a[id][id] = 1;
                    continue;
                }
                a[id][id] = 1; a[id][n*m] = 1;
                for (int r=0;r<4;r++)
                {
                    int ni = i+di[r], nj = j+dj[r];
                    if (!inside(ni, nj) || plat[ni][nj] == '#') continue;
                    int nid = ni * m + nj;
                    a[id][nid] = -1.0 / d[id];
                }
            }
/*
        for (int i=0;i<n*m;i++)
        {
            for (int j=0;j<=n*m;j++)
                printf("%.3f ", a[i][j]);
            puts("");
        }
        puts("-------------");
*/
        Gauss_Elimination(a, n*m);
/*
        for (int i=0;i<n*m;i++)
        {
            for (int j=0;j<=n*m;j++)
                printf("%.3f ", a[i][j]);
            puts("");
        }
        puts("-------------");
*/
        printf("%.3f\n", a[st][n*m]);
    }
    return 0;
}
