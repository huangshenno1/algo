#include <cstdio>

const int maxn = 100010;

int n, ans;
int h[maxn], l[maxn], r[maxn];

int main()
{
    while (~scanf("%d", &n))
    {
        h[0] = h[n+1] = 0;
        for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
        for (int i = 1, st = 1; i <= n; i++)
        {
            if (h[i] < h[i-1]) st = i;
            l[i] = st;
        }
        for (int i = n, st = n; i >= 1; i--)
        {
            if (h[i] < h[i+1]) st = i;
            r[i] = st;
        }
        ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (r[i] - l[i] + 1 > ans)
                ans = r[i] - l[i] + 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}