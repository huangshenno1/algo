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

const int maxn = 100010;
int T, n, d, k = 3, idx, q, m, x;

struct Point
{
    int x[5];
    bool operator < (const Point &o) const {return x[idx] < o.x[idx];}
}p[maxn], a[maxn];

typedef pair<int, Point> tp;
priority_queue<tp> nq;

Point pt[maxn << 2];
int son[maxn << 2];

void buildKD(int l, int r, int rt = 1, int dep = 0)
{
    if (l > r) return;
    son[rt] = r - 1;
    son[rt<<1] = son[rt<<1|1] = -1;
    idx = dep % k;
    int mid = (l + r) >> 1;
    nth_element(p+l, p+mid, p+r+1);
    pt[rt] = p[mid];
    buildKD(l, mid-1, rt<<1, dep+1);
    buildKD(mid+1, r, rt<<1|1, dep+1);
}

void find(Point a, int m, int rt = 1, int dep = 0)
{
    if (son[rt] == -1) return;
    tp node(0, pt[rt]);
    for (int i = 0; i < k; i++) node.first += (a.x[i]-pt[rt].x[i]) * (a.x[i]-pt[rt].x[i]);
    int dim = dep % k, lhs = rt << 1, rhs = rt << 1 | 1, flag = 0;
    if (a.x[dim] >= pt[rt].x[dim]) swap(lhs, rhs);
    if (son[lhs] != -1) find(a, m, lhs, dep+1);
    if (nq.size() < m) nq.push(node), flag = 1;
    else
    {
        if (node.first < nq.top().first) nq.pop(), nq.push(node);
        if ((a.x[dim]-pt[rt].x[dim])*(a.x[dim]-pt[rt].x[dim]) < nq.top().first) flag = 1;
    }
    if (son[rhs] != -1 && flag) find(a, m, rhs, dep+1);
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &d);
        for (int i=1;i<=n;i++)
        {
            for (int j=0;j<3;j++)
                scanf("%d", &p[i].x[j]);
            a[i] = p[i];
        }
        buildKD(1, n);
        scanf("%d", &q);
        while (q--)
        {
            scanf("%d", &x);
            while (!nq.empty()) nq.pop();
            find(a[x], 2);
            int ans = nq.top().first;
            if (ans > d*d) puts("no point nearby");
            else printf("%.3lf\n", sqrt((double)ans));
        }
    }
    return 0;
}
