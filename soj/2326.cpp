#include <cstdio>
#include <cstring>

#define N 1000001
#define NN 1001
int p[N],f[N],g[N];

void init()
{
    int i,j;
    int count,t;
    memset(p,-1,sizeof(p));
    for (i=2;i<NN;i++)
    {
        for (j=i;i*j<N;j++)
        {
            if (p[i*j]==-1)
                p[i*j]=j;
        }
    }

    f[0]=f[1]=0;
    for (i=2;i<N;i++)
    {
        count=1;
        t=i;
        while (p[t]!=-1)
        {
            t=p[t];
            count++;
        }
        f[i]=count;
    }
    
    g[0]=0;
    for (i=1;i<N;i++)
    {
        g[i]=g[i-1]+f[i];
    }
}

int main()
{
    int n;
    init();
    while (~scanf("%d",&n))
    {
        printf("%d\n",g[n]);
    }
    return 0;
}