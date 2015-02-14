#include <cstdio>

int main()
{
    int T,n;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d", &n);
        int even = (n + 1) / 2;
        int odd = even - (int)(((int)((n - 1) / 3) + 1) / 2);
        printf("%d\n", even + odd);
    }
    return 0;
}