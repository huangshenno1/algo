#include <cstdio>
#include <cstring>

const int maxn = 50010;
int n,a[maxn],i,Max;
int b[maxn],l[maxn],r[maxn];
long long ans;

int lowbit(int k)
{
    return k&(k^(k-1));
}

int sum(int k)
{
    int s=0;
    while (k>0)
    {
        s+=b[k];
        k-=lowbit(k);
    }
    return s;
}

void add(int p,int d)
{
    while (p<=Max)
    {
        b[p]+=d;
        p+=lowbit(p);
    }
}

int main()
{
    while (scanf("%d",&n)==1)
    {
        Max=0;
        for (i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if (a[i]+1>Max)
                Max=a[i]+1;
        }

        memset(b,0,sizeof(b));
        for (i=1;i<=n;i++)
        {
            l[i]=sum(a[i]);
            add(a[i]+1,1);
        }

        memset(b,0,sizeof(b));
        for (i=n;i>=1;i--)
        {
            r[i]=sum(a[i]);
            add(a[i]+1,1);
        }

        ans=0;
        for (i=1;i<=n;i++)
            ans=ans+l[i]*r[i];

        printf("%lld\n",ans);
    }
    return 0;
}