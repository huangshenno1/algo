#include <stdio.h>

int main()
{
    int t,n,ans;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        ans=n/=5;
        while (n)
            ans+=n/=5;
        printf("%d\n",ans);
    }
}