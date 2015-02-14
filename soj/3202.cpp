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

int T;
int n, m, ans;
map<string, int> dic;
string tmp, tmp2;
int p, q;
struct Node
{
    int p, q;
    Node(int p, int q): p(p), q(q) {}
};
vector<Node> a[1010];
int tot;

int f(int q)
{
    int sum = 0;
    for (int i=0;i<tot;i++)
    {
        p = 1e9;
        for (int j=0;j<a[i].size();j++)
            if (a[i][j].q >= q && a[i][j].p < p)
                p = a[i][j].p;
        sum += p;
    }
    return sum;
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        dic.clear(); tot = 0;
        for (int i=0;i<n;i++)
        {
            cin >> tmp >> tmp2;
            scanf("%d%d", &p, &q);
            if (dic.find(tmp) == dic.end())
            {
                a[tot].push_back(Node(p, q));
                dic[tmp] = tot++;
            }
            else a[dic[tmp]].push_back(Node(p, q));
        }

        int low = 0, high = 1e9;
        for (int i=0;i<tot;i++)
        {
            q = 0;
            for (int j=0;j<a[i].size();j++)
                q = max(q, a[i][j].q);
            high = min(high, q);
        }

        ans = 0;
        while (low <= high)
        {
            int mid = (low + high) >> 1;
            int sum = f(mid);
            if (sum <= m)
            {
                if (mid > ans) ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        printf("%d\n", ans);

        for (int i=0;i<tot;i++) a[i].clear();
    }
    return 0;
}
