#include <stdio.h>

int main()
{
    int f[51]={1,1,1};
    int p=2;
    int n;
    int i;
    int t;
    int iCase;
    scanf("%d",&t);
    for (iCase=0;iCase<t;iCase++)
    {
        scanf("%d",&n);
        if (n>p)
        {
            for (i=p+1;i<=n;i++)
            {
                f[i]=f[i-1]-2*f[i-2]+3*f[i-3];
            }
            p=n;
        }
        printf("%d\n",f[n]);
    }
    return 0;
}