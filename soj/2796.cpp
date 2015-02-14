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

const int maxn = 210;
char a[maxn],b[maxn];
int la,lb;
int dp[maxn][maxn];

int main()
{
    while (scanf("%s%s",a+1,b+1)==2)
    {
        la=strlen(a+1); lb=strlen(b+1);
        for (int i=0;i<=la;i++) dp[i][0]=0;
        for (int i=0;i<=lb;i++) dp[0][i]=0;
        for (int i=1;i<=la;i++)
            for (int j=1;j<=lb;j++)
                dp[i][j]=max(dp[i-1][j-1]+(a[i]==b[j]), max(dp[i-1][j],dp[i][j-1]));
        printf("%d\n",dp[la][lb]);
    }
    return 0;
}
