#include <cstdio>

const int maxn = 1005;
int T, n;
int a[maxn], s[maxn];

void init()
{
    for (int i=1;i<1000;i++)
    {
        a[i] = i*i*i;
        s[i] = ((i+1)*(i+1)*(i+1)-1) / i - (i*i*i-1) / i;
    }
    a[1000] = 1000000000;
    s[1000] = 1;
}

int main()
{
    init();
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        int i = 2, ans = 0;
        while (n >= a[i])
        {
            ans += s[i-1];
            i++;
        }
        i--;
        ans += n/i - (a[i]-1)/i;
        printf("%d\n", ans);
    }
    return 0;
}