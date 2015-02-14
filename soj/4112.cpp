#include <stdio.h>

void main()
{
    int t,k;
    int n;
    int i;
    int f[1001]={0,1,2};
    for (i=3;i<=1000;i++)
    {
        f[i]=(f[i-1]+f[i-2])%2012;
    }
    scanf("%d",&t);
    for (k=0;k<t;k++)
    {
        scanf("%d",&n);
        printf("Case #%d: %d\n",k+1,f[n]);
    }
}