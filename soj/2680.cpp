#include <cstdio>
#include <cstring>

int n;
int a[32];
long long f[1001];

int main()
{
    int i,j;
    for (i=0;i<32;i++)
        a[i]=i*i;
    memset(f,0,sizeof(f));
    f[0]=1;
    for (j=1;j<32;j++)
    {
        for (i=a[j];i<=1000;i++)
        {
            if (i>=a[j])
                f[i]=f[i-a[j]]+f[i];
        }
    }
    while (scanf("%d",&n)==1 && n)
    {
        printf("%lld\n",f[n]);
    }
    return 0;
}