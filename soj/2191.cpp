#include <cstdio>
#include <cstring>

#define N 1000000
#define NN 1000

long long p[N+1];
long long f[N+1];

long long Euler(long long x)
{
    long long ans=x;
    long long last=-2;
    
    if (p[x]==-1)
    {
        return x-1;
    }

    while (p[x]!=-1)
    {
        if (p[x]!=last)
        {
            last=p[x];
            ans=ans*(last-1)/last;
        }
        x=x/p[x];
    }
    if (x!=last)
    {
        last=x;
        ans=ans*(last-1)/last;
    }
    return ans;
}

void Init()
{
    memset(p,-1,sizeof(p));
    for (long long i=2;i<=NN;i++)
    {
        for (long long j=i;i*j<=N;j++)
        {
            if (p[i*j]==-1)
                p[i*j]=i;
        }
    }

    f[2]=1;
    for (long long i=3;i<=N;i++)
    {
        f[i]=f[i-1]+Euler(i);
    }
}

int main()
{
    Init();
    long long n;
    while (scanf("%lld",&n)==1 && n)
        printf("%lld\n",f[n]);
    return 0;
}