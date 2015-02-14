#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn = 1000005;
int n;
pair<int,int> a[maxn];
int order[maxn], h[1<<21];

int main()
{
    while (scanf("%d", &n) == 1)
    {
        for (int i=0;i<n;i++)
            scanf("%d", &a[i].first), a[i].second = i;
        sort(a, a+n);
        for (int i=0;i<n;i++)
            order[a[i].second] = n-1-i;
        memset(h, 0, sizeof(h));
        ll ans = 0;
        for (int i=0;i<n;i++)
        {
            int p = order[i] + (1<<20);
            while (p)
            {
                if (p&1) ans += ll(h[p-1]);
                h[p]++;
                p /= 2;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
