#include <cstdio>
#include <cstring>
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

#define ll long long
#define pii pair<int, int>
#define fr first
#define sc second
#define mp make_pair
#define FOR(i,j,k) for(int i=j;i<=(k);i++)
#define FORD(i,j,k) for(int i=j;i>=(k);i--)
#define REP(i,n) for(int i=0;i<(n);i++)

const int maxn = 50005;
int n, cnt[maxn], x;
bool notprime[maxn];
int nprime, prime[maxn], mu[maxn];
ll sum[maxn], ans, tmp;

void getmu()
{
    nprime=0;
    mu[1]=1;
    for (int i=2;i<maxn;i++)
    {
        if (!notprime[i]) {prime[nprime++]=i; mu[i]=-1;}
        for (int j=0;j<nprime&&i*prime[j]<maxn;j++)
        {
            notprime[i*prime[j]]=1;
            if (i%prime[j]) mu[i*prime[j]]=-mu[i];
            else {mu[i*prime[j]]=0; break;}
        }
    }
}

int main()
{
    getmu();
    while (scanf("%d", &n) == 1)
    {
        memset(cnt, 0, sizeof(cnt));
        for (int i=1;i<=n;i++)
        {
            scanf("%d", &x);
            cnt[x]++;
        }
        for (int i=1;i<maxn;i++)
        {
            tmp = 0;
            for (int j=i;j<maxn;j+=i) tmp += (ll)cnt[j] * j;
            sum[i] = tmp * tmp;
        }
        ans = 0;
        for (int i=1;i<maxn;i++)
        {
            tmp = 0;
            for (int j=1;i*j<maxn;j++) tmp += mu[j] * sum[i*j];
            ans += tmp / i;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
