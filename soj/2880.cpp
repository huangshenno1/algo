#include <cstdio>
#include <cstring>

#define N 1000001
#define NN 1000

int h[N+1];
int flag[N+1];
int f[N+1];

void Init()
{
    int i,j;
    memset(h,0,sizeof(h));
    for (i=5;i<=N;i+=4)
        h[i]=1;
    for (i=5;i<NN;i+=4)
        for (j=i*i;j<=N;j+=i*2)
            h[j]=0;

    memset(flag,0,sizeof(flag));
    for (i=5;i<NN;i+=4)
    {
        if (h[i]&&!flag[i])
        {
            for (j=i;i*j<=N;j+=4)
            {
                if (h[j])
                    flag[i*j]=1;
            }
        }
    }

    f[0]=0;
    for (i=1;i<=N;i++)
        f[i]=f[i-1]+flag[i];
}

int main()
{
    Init();
    int n;
    while (~scanf("%d",&n) && n)
        printf("%d %d\n",n,f[n]);
    return 0;
}