#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <algorithm>
using namespace std;

typedef long long ll;
int T,n,m;
int a[1010][60];
ll dp[1010][60],sum[60],l[60],r[60],s,tmp,ans,minll;

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&m);
        minll=0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                scanf("%d",&a[i][j]);
                if (a[i][j]<0) minll=minll+a[i][j];
            }
        for (int j=1;j<=m;j++) dp[1][j]=0;
        for (int i=2;i<=n+1;i++)
            for (int j=1;j<=m;j++)
                dp[i][j]=minll;
        ans=a[1][1];
        for (int i=1;i<=n;i++)
        {
            sum[0]=0;
            for (int j=1;j<=m;j++) sum[j]=sum[j-1]+a[i][j];
            l[1]=0;
            for (int j=2;j<=m;j++) l[j]=max(l[j-1]+a[i][j-1],0LL);
            r[m]=0;
            for (int j=m-1;j>=1;j--) r[j]=max(r[j+1]+a[i][j+1],0LL);
            for (int j=1;j<=m;j++)
                for (int k=1;k<=m;k++)
                {
                    if (k>=j) s=sum[k]-sum[j-1]+l[j]+r[k];
                    else s=sum[j]-sum[k-1]+l[k]+r[j];
                    dp[i+1][k]=max(dp[i+1][k],dp[i][j]+s);
                    if (dp[i+1][k]>ans) ans=dp[i+1][k];
                }
        }
        printf("%lld\n",ans);
    }
    return 0;
}