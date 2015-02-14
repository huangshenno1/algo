#include <cstdio>

int main()
{
    int n,ans,i,a;
    while (scanf("%d",&n) == 1)
    {
        ans=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a);
            if (a) ans^=i;
        }
        if(ans)
            puts("yes");
        else
            puts("no");
    }
    return 0;
}