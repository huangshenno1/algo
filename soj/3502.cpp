#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll INF = 10000000000;
const int MAXN = 2100;
ll a[MAXN],b[MAXN];
int tot;

void gen(ll x)
{
    if (x>INF) return;
    b[tot++]=x;
    gen(x*10+4);
    gen(x*10+7);
}

void init()
{
    tot=0;
    gen(4);
    gen(7);
    sort(b,b+tot);
    int l=0;
    for (int i=0;i<tot;i++)
    {
        bool flag=1;
        for (int j=0;j<l;j++)
            if (b[i]%a[j]==0) {flag=0; break;}
        if (flag) a[l++]=b[i];
    }
    tot=l;
    reverse(a,a+tot);
    //for (int i=0;i<tot;i++) printf("%lld ",a[i]);
    //printf("\ntot = %d\n",tot);
}

ll gcd(ll a,ll b)
{
    return b?gcd(b,a%b):a;
}
ll lcm(ll a,ll b)
{
    if ((double)a/(double)gcd(a,b)*(double)b>10000000000.0) return 10000000001LL;
    return a/gcd(a,b)*b;
}

ll dfs(ll x,ll y,ll s,int k)
{
    if (s>y) return 0;
    ll ret=y/s-x/s;
    for (int i=k+1;i<tot;i++)
        ret-=dfs(x,y,lcm(s,a[i]),i);
    //printf("%lld %lld\n",s,ret);
    return ret;
}

ll f(ll x,ll y)
{
    ll ret=0;
    int st=0;
    while (a[st]>y) st++;
    for (int i=st;i<tot;i++)
        ret+=dfs(x,y,a[i],i);
    return ret;
}

int main()
{
    init();
    ll x=1,y=10000000000LL;
    //printf("%lld\n",f(x-1,y));
    while (scanf("%lld%lld",&x,&y)==2)
        printf("%lld\n",f(x-1,y));
    return 0;
}
