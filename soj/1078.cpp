#include <cstdio>
#include <algorithm>
using namespace std;

struct Job
{
    int st, ed;
    bool operator < (const Job &jb) const
    {
        return ed < jb.ed;
    }
};

const int maxn = 1005;
int n;
Job a[maxn];

int main()
{
    while (scanf("%d", &n) == 1 && n)
    {
        for (int i=1;i<=n;i++) scanf("%d%d", &a[i].st, &a[i].ed);
        sort(a+1, a+n+1);
        int ans = 0, t = 0;
        for (int i=1;i<=n;i++)
        {
            if (a[i].st >= t)
            {
                ans++;
                t = a[i].ed;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}