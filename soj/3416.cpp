#include <cstdio>
#include <cstring>

bool xprime[3000010];
int f[1000010];

void init()
{
    memset(xprime,0,sizeof(xprime));
    for (int i=2;i<2000;i++)
        for (int j=i;i*j<3000010;j++)
            xprime[i*j]=1;
    memset(f,0,sizeof(f));
    for (int i=2;i<=1000000;i++)
        f[i]=f[i-1]+(xprime[3*i+7] ? 0:1);
}

int main()
{
    int t,x;
    init();
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&x);
        printf("%d\n",f[x]);
    }
    return 0;
}