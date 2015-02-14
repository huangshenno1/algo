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

const int maxn = 100010;
int n,a[maxn],sum[maxn],f[maxn],g[maxn],q[maxn];

int main()
{
    while (~scanf("%d",&n))
    {
        sum[0]=0;
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum[i]=sum[i-1]+a[i];
        }
        q[1]=n+1;
        int h=1,t=1;
        for (int i=n;i>=1;i--)
        {
            while (h<t && f[q[h+1]]<=sum[q[h+1]-1]-sum[i-1]) h++;
            f[i]=sum[q[h]-1]-sum[i-1];
            g[i]=g[q[h]]+1;
            q[++t]=i;
            while (h<t && f[q[t-1]]-sum[q[t-1]-1]+sum[q[t]-1]>f[q[t]]) t--,q[t]=q[t+1];
        }
        printf("%d\n",g[1]);
    }
    return 0;
}
