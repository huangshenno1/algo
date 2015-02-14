#include <cstdio>

int main()
{
    int t,n,ans,i;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        ans=1;
        for (i=2;i*i<=n;i++)
        {
            if (n%i==0)
            {
                n/=i;
                while (n%i==0)
                {
                    n/=i;
                    ans*=i;
                }
            }
        }
        printf("%d\n",ans+1);
    }
    return 0;
}