#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn = 100005;
int n, i, j;
int a[maxn];
ll k, c;
int ans1, ans2;

int main()
{
    while (scanf("%d%lld", &n, &k) == 2)
    {
        for (int i=0;i<n;i++) scanf("%d", &a[i]);
        sort(a, a+n);
        i = 0;
        while (k > 0)
        {
            c = 1;
            for (j=i+1;j<n && a[j] == a[i];j++, c++);
            if (k <= c*n)
            {
                ans1 = a[i];
                ans2 = a[(k-1)/c];
                break;
            }
            else k -= c*n;
            i = j;
        }
        printf("%d %d\n", ans1, ans2);
    }
    return 0;
}