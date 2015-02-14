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

int T,n,m,ans;
int s[110];
int a[510][110];

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++) scanf("%d",&s[i]);
        for (int j=1;j<=m;j++)
            for (int i=1;i<=n;i++)
                scanf("%d",&a[j][i]);
        bool flag=0;
        for (int j=1;j<=m;j++)
        {
            for (int i=1;i<=n;i++)
            {
                s[i]-=a[j][i];
                if (s[i]<=0) {ans=i; flag=1; break;}
            }
            if (flag) break;
        }
        if (flag) printf("%d\n",ans);
        else puts("Impossible");
    }
    return 0;
}
