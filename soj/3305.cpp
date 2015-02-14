#include <stdio.h>

bool g(int n)
{
    int ans=0;
    while (n)
    {
        if (n&1)
            ans++;
        n>>=1;
    }
    if (ans&1)
        return 0;
    else return 1;
}

int main()
{
    int t,n;
    int ans;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        ans=2*n;
        if (!g(ans))
            ans++;
        printf("%d\n",ans);
    }
    return 0;
}