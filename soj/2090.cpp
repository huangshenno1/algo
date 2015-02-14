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
const int maxn = 1010;
int T,n,m,cnt[maxn],a,b;
ll ans;

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&m);
        memset(cnt,0,sizeof(cnt));
        ans=0;
        while (m--)
        {
            scanf("%d%d",&a,&b);
            cnt[a]++; cnt[b]++;
        }
        for (int i=1;i<=n;i++)
            ans+=cnt[i]*(n-1-cnt[i]);
        ans=n*(n-1)*(n-2)/6-(ans>>1);
        printf("%lld\n",ans);
    }
    return 0;
}
