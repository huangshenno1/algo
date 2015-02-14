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

const int maxn = 100010;
int T,n,s,ans;
int a[maxn],b[maxn];
map<int,int> f;

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        for (int i=1;i<=n;i++) scanf("%d",&b[i]);
        ans=0; s=0;
        f.clear(); f[0]=0;
        for (int i=1;i<=n;i++)
        {
            s+=a[i]-b[i];
            if (f.find(s)==f.end()) f[s]=i;
            else ans=max(ans,i-f[s]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
