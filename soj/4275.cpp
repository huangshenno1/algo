#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
using namespace std;

int n,m,t;
long long ans;
int prime[100000],pp,cnt;

void init()
{
    prime[0]=2;
    pp=1;
    for (int i=3;i<=200000;i+=2)
    {
        bool f=1;
        for (int j=0;j<pp;j++)
            if (i%prime[j]==0) {f=0; break;}
        if (f) prime[pp++]=i;
    }
}

int count(int a,int b)
{
    int res=0;
    while (a>=b)
    {
        res+=a/b;
        a/=b;
    }
    return res;
}

long long pow_mod(long long x,int y)
{
    long long res=1;
    while (y)
    {
        if (y&1) res=(res*x)%m;
        x=(x*x)%m;
        y>>=1;
    }
    return res;
}

int main()
{
    init();
    while (scanf("%d%d",&n,&m)==2)
    {
        ans=1;
        for (int i=0;i<pp;i++)
        {
            cnt=count(n+n,prime[i])-count(n,prime[i])-count(n+1,prime[i]);
            ans=(ans*pow_mod(prime[i],cnt))%m;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
