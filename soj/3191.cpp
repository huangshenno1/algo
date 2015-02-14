#include <cstdio>
#include <cstring>
typedef long long ll;
const int maxn = 41000;
bool notprime[maxn];
int prime2[maxn], cntprime;

void prime_table()
{
    memset(notprime,0,sizeof(notprime));
    cntprime=0;
    for (int i=2;i<maxn;i++)
    {
        if (notprime[i]) continue;
        prime2[cntprime++]=i*i;
        for (int j=i*i;j<maxn;j+=i)
            notprime[j]=1;
    }
}

int dfs(int n,int s,int i)
{
    int res=n/s;
    for (int j=i+1;n/s>=prime2[j];j++)
        res-=dfs(n,s*prime2[j],j);
    return res;
}

int g(int n)
{
    int res=0;
    for (int i=0;prime2[i]<=n;i++)
        res+=dfs(n,prime2[i],i);
    return res;
}

int f(int n)
{
    return n-g(n);
}

int main()
{
    prime_table();
    int T,n;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        unsigned int low=1,high=1644934081,mid;
        while (low<=high)
        {
            mid=(low+high)>>1;
            int tmp1=f(mid),tmp2=f(mid-1);
            //printf("%u %u %u %d %d\n",low,high,mid,tmp1,tmp2);
            if (tmp1==n && tmp2==n-1) break;
            else if (tmp1==n) high=mid;
            else if (tmp1<n) low=mid+1;
            else high=mid-1;
        }
        printf("%u\n",mid);
    }
    return 0;
}
