#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <ctime>
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
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int mod = 1000000007;
const int maxn = 46340;

bool notprime[maxn];
int prime[10000], nprime;

void prime_table()
{
    memset(notprime,0,sizeof(notprime));
    nprime=0;
    for (int i=2;i<maxn;i++)
    {
        if (notprime[i]) continue;
        prime[nprime++]=i;
        for (int j=i*i;j<maxn;j+=i)
            notprime[j]=1;
    }
}

int T,n,m,k;

int cal(int x, int p)
{
    int ret = 0;
    while (x)
    {
        x /= p;
        ret += x;
    }
    return ret;
}

int main()
{
    prime_table();
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d%d",&n,&m,&k);
        if (k==1) {puts("Yes"); continue;}
        bool go=1;
        for (int i=0;i<nprime && prime[i]<=k;i++)
        {
            if (k%prime[i]) continue;
            int cnt=0;
            while (k%prime[i]==0) {cnt++; k/=prime[i];}
            if (cal(n,prime[i])-cal(n-m,prime[i])-cal(m,prime[i])<cnt)
                {go=0; break;}
        }
        if (k>1)
        {
            if (cal(n,k)-cal(n-m,k)-cal(m,k)<1) go=0;
        }
        if (go) puts("Yes");
        else puts("No");
    }
    return 0;
}
