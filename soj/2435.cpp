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

int T,m,n;
int a[20][20];
int dp[20][20];

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&m,&n);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                scanf("%d",&a[i][j]);
        memset(dp,0,sizeof(dp));
        dp[1][0]=1;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                if (!a[i][j]) continue;
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        printf("%d\n",dp[n][m]);
    }
    return 0;
}
