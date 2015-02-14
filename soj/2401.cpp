#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn = 100010;
int n, D, W, ans, k;
struct Node
{
    int d, w;
    bool operator < (const Node & o) const {return d < o.d;}
}a[maxn];
priority_queue<int> Q;

int main()
{
    while (scanf("%d", &n) == 1)
    {
        scanf("%d%d", &D, &W);
        for (int i=0;i<n;i++) scanf("%d%d", &a[i].d, &a[i].w);
        sort(a, a+n);
        while (!Q.empty()) Q.pop();
        for (k=0;k<n && a[k].d<=W;k++) Q.push(a[k].w);
        ans = 0;
        while (W < D && !Q.empty())
        {
            int w = Q.top(); Q.pop();
            W += w;
            ans ++;
            for (;k<n && a[k].d<=W;k++) Q.push(a[k].w);
        }
        if (W < D) puts("-1");
        else printf("%d\n", ans);
    }
    return 0;
}
