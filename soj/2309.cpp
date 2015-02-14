#include <cstdio>
#include <cstring>

const int maxn = 10010;

int n,k,ans,r,t;
int a[maxn],c[maxn];

int lowbit(int x) {return x&-x;}

void add(int x, int d)
{
    while (x <= n)
    {
        c[x] += d;
        x += lowbit(x);
    }    
}

int sum(int x)
{
    int ret = 0;
    while (x > 0)
    {
        ret += c[x];
        x -= lowbit(x);
    }
    return ret;
}

int main()
{
    while (scanf("%d%d",&n,&k)==2)
    {
        ans=1;t=0;
        for (int j=1;j<=k;j++)
        {
            memset(c,0,sizeof(c));
            r=0;
            for (int i=0;i<n;i++)
                scanf("%d",&a[i]);
            for (int i=n-1;i>=0;i--)
            {
                r+=sum(a[i]);
                add(a[i],1);
            }
            if (r>t) {t=r; ans=j;}
        }
        printf("%d\n",ans);
    }
    return 0;
}