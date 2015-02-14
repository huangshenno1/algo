#include <stdio.h>

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    while (n||m)
    {
        if (n>0)
        {
            int f[10010]={0,1,2,3};
            for (int i=4;i<=n;i++)
            {
                f[i]=(f[i-3]+f[i-1])%m;
            }
            for (int i=1;i<=3;i++)
            {
                f[i]=f[i]%m;
            }
            printf("%d\n",f[n]);
        }
        else
        {
            printf("%d\n",(m+n%m)%m);
        }
        scanf("%d%d",&n,&m);
    }
    return 0;
}