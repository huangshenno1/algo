#include <cstdio>

const int maxn = 1000001;
int T,n;
int cnt[maxn];

void init()
{
    for (int i=0;i<maxn;i++)
        cnt[i]=0;
    for (int i=1;i*i<maxn;i++)
        for (int j=i;i*j<maxn;j++)
            cnt[i*j]++;
}

void find(int x)
{
    for (int i=1;i<maxn;i++)
    {
        if (cnt[i]==x)
        {
            printf("%d\n",i);
            return;
        }
    }
    printf("Too big\n");
}

int main()
{
    init();
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        find(n);
    }
    return 0;
}