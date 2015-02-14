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

typedef long long ll;
const int mod = 1000000007;
const int maxn = 100010;
int x,y,k;
ll C[maxn]; //C(k,i)

ll inv(ll a)
{
    ll ret=1;
    int n=mod-2;
    while (n)
    {
        if (n&1) ret=(ret*a)%mod;
        a=(a*a)%mod;
        n>>=1;
    }
    return ret;
}

int main()
{
    while (scanf("%d%d%d",&x,&y,&k)==3)
    {
        if ((k-abs(x)-abs(y))&1 || abs(x)+abs(y)>k) {puts("0"); continue;}
        C[0]=1;
        for (int i=1;i<=k;i++)
            C[i]=(C[i-1]*((inv(i)*(k-i+1))%mod))%mod;
        printf("%lld\n",(C[(k-x-y)/2]*C[(k-x+y)/2])%mod);
    }
    return 0;
}
