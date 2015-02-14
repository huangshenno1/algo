#include <cstdio>

const int maxn = 1000001;
int n,a[4],i,j;
bool f[maxn],e;

int main()
{
    f[0]=1,f[1]=0,a[0]=1;
    while (scanf("%d%d%d%d",&n,&a[1],&a[2],&a[3])==4)
    {
        for (i=2;i<=n;i++)
        {
            f[i]=0;
            for (j=0;j<4;j++)
            {
                if (i>a[j] && f[i-a[j]]==0)
                {
                    f[i]=1;
                    break;
                }
            }
        }
        if (f[n]==1)
            printf("yes\n");
        else printf("no\n");
    }
    return 0;
}