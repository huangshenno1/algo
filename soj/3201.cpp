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

int T, cas = 1, n, nn, m, st;
string name1, name2;
map<string, int> dic;
int g[105][105], num[105][105], u, v, d;
double ans;

struct Road
{
    int u, v, d;
}r[55];

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &m);
        dic.clear(); n = 1;
        cin >> name1;
        dic[name1] = st = 0;
        memset(g, 0x3f, sizeof(g));
        memset(num, 0, sizeof(num));

        for (int i=0;i<m;i++)
        {
            cin >> name1 >> name2 >> d;
            if (dic.find(name1) == dic.end()) dic[name1] = n++;
            u = dic[name1];
            if (dic.find(name2) == dic.end()) dic[name2] = n++;
            v = dic[name2];
            r[i].u = u; r[i].v = v; r[i].d = d;
            if (g[u][v] > d)
            {
                g[u][v] = d;
                num[u][v] = 1;
            }
            else if (g[u][v] == d)
                num[u][v] ++;
        }

        for (int k=0;k<n;k++)
            for (int i=0;i<n;i++)
                for (int j=0;j<n;j++)
                {
                    if (i==k || j==k) continue;
                    if (g[i][j] > g[i][k] + g[k][j])
                    {
                        g[i][j] = g[i][k] + g[k][j];
                        num[i][j] = num[i][k] * num[k][j];
                    }
                    else if (g[i][j] == g[i][k] + g[k][j])
                        num[i][j] += num[i][k] * num[k][j];
                }

        for (int i=0;i<n;i++)
        {
            g[i][i] = 0;
            num[i][i] = 1;
        }

        nn = 0;
        for (int i=0;i<n;i++)
        {
            if (i == st) continue;
            if (g[st][i] < 0x3f3f3f3f) nn++;
        }
        printf("Case #%d:", cas++);
        for (int i=0;i<m;i++)
        {
            u = r[i].u; v = r[i].v; d = r[i].d;
            ans = 0;
            if (g[st][v] == g[st][u] + d)
                for (int j=0;j<n;j++)
                {
                    if (g[st][j] == g[st][v] + g[v][j])
                        ans += (double)num[st][u] * num[v][j] / ((double)nn * num[st][j]);
                }
            printf(" %.7lf", ans);
        }
        puts("");
    }
    return 0;
}
