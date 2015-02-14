#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 500010;

int n;
long long ans;
struct node
{
    int num;
    int w;
}a[maxn];
int c[maxn];

int cmpn(const node a1,const node a2) {return a1.num<a2.num;}
int cmpw(const node a1,const node a2) {return a1.w<a2.w;}

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
    int i,t;
    while (scanf("%d",&n)==1 && n)
    {

        for (i=1;i<=n;i++)
        {
            a[i].num=i;
            scanf("%d",&a[i].w);
        }
        sort(a+1,a+n+1,cmpw);
        for (i=1;i<=n;i++)
            a[i].w=i;
        sort(a+1,a+n+1,cmpn);
        memset(c,0,sizeof(c));
        ans=0;
        for (i=n;i>=1;i--)
        {
            ans=ans+sum(a[i].w-1);
            add(a[i].w,1);
        }
        printf("%lld\n",ans);
    }
    return 0;
}