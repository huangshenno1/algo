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
const int maxn = 1000010;

int n;
ll m,a[maxn],mmax,mmin;

bool check(ll h)
{
    ll sum=0;
    for (int i=1;i<=n;i++)
        sum+=(a[i]>h)?a[i]-h:0;
    return sum>=m;
}

int main()
{
    while (scanf("%d%lld",&n,&m)==2)
    {
        mmax=0; mmin=2000000000;
        for (int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            mmax=max(mmax,a[i]);
            mmin=min(mmin,a[i]);
        }
        ll low=0,high=mmax,mid;
        while (low<=high)
        {
            mid=(low+high)>>1;
            int c=check(mid),cc=check(mid+1);
            if (c&&!cc) break;
            else if (c) low=mid+1;
            else high=mid-1;
        }
        printf("%lld\n",mid);
    }
    return 0;
}
