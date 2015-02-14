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
const int maxn = 110;

int n,m;
int a[maxn];
int ans;

int main()
{
    while (scanf("%d%d",&n,&m)==2)
    {
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        ans=0;
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++)
                for (int k=j+1;k<=n;k++)
                {
                    int sum=a[i]+a[j]+a[k];
                    if (sum<=m && sum>ans) ans=sum;
                }
        printf("%d\n",ans);
    }
    return 0;
}
