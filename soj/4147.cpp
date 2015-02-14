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
const int maxn = 210;

int dp[maxn][maxn];

int f(int n,int k)
{
    if (dp[n][k]>=0) return dp[n][k];
    if (n<k || k==0) return dp[n][k]=0;
    if (k==1 || k==n) return dp[n][k]=1;
    int ret=0;
    for (int i=0;i<=k;i++)
        ret+=f(n-k,i);
    return dp[n][k]=ret;
}

int main()
{
    int n,k;
    memset(dp,-1,sizeof(dp));
    while (scanf("%d%d",&n,&k)==2)
        printf("%d\n",f(n,k));
    return 0;
}
