#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int n, m;
int a[maxn], b[maxn];

int main()
{
    while (scanf("%d%d", &n, &m) == 2)
    {
        for (int i=1;i<=n;i++) scanf("%d", &a[i]);
        for (int i=1;i<=m;i++) scanf("%d", &b[i]);
        sort(a+1, a+n+1); sort(b+1, b+m+1);
        int ans = 0, i = 1, j = 1;
        while (j <= m)
        {
            while (a[i] < b[j]) i++;
            ans += a[i] - b[j];
            j++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
