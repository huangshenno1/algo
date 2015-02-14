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

const double eps = 1e-8;
const int maxn = 10005;
int T, n;
int a[maxn], b[maxn], c[maxn];

inline double f(double x, int i)
{
    return (a[i] * x + b[i]) * x + c[i];
}

double F(double x)
{
    double ret = -1e300;
    for (int i=0;i<n;i++)
        ret = max(ret, f(x, i));
    return ret;
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i=0;i<n;i++) scanf("%d%d%d", &a[i], &b[i], &c[i]);
        double low = 0, high = 1000, mid1, mid2;
        while (low + eps < high)
        {
            mid1 = (low + low + high) / 3;
            mid2 = (low + high + high) / 3;
            if (F(mid1) < F(mid2)) high = mid2;
            else low = mid1;
        }
        double ans = F((low + high) / 2);
        printf("%.4lf\n", ans);
    }
    return 0;
}
