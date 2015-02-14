#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100010;

int n;
long long ans,s;
int a[maxn],b[maxn],c[maxn];

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
    int i;
    while (scanf("%d",&n)==1)
    {
        for (i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            b[a[i]]=i;
        }
        memset(c,0,sizeof(c));
        ans=0;
        for (i=n;i>=1;i--)
        {
            ans=ans+sum(a[i]-1);
            add(a[i],1);
        }
        s=ans;
        for(i=1;i<=n;i++)
        {
            s=s+(n-b[i])-(b[i]-1);
            ans=min(ans,s);
        }
        printf("%lld\n",ans);
    }
    return 0;
}