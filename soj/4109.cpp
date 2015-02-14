#include <stdio.h>

int main()
{
    long long f[31]={1,1,2,5};
    for (int i=4;i<=30;i++)
    {
        f[i]=f[i-1]*(4*i-2)/(i+1);
    }
    int t;
    int n;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        printf("%lld\n",f[n]);
    }
    return 0;
}