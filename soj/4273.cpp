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

const int maxn = 101;
int a,b,c;
double dp[maxn][maxn][maxn];

int main()
{
    while (scanf("%d%d%d",&a,&b,&c)==3 && a)
    {
        memset(dp,0,sizeof(dp));
        for (int i=a;i>=0;i--)
            for (int j=b;j>=0;j--)
                for (int k=c;k>=0;k--)
                {
                    if (i==a&&j==b&&k==c) continue;
                    dp[i][j][k] = a*b*c
                                + dp[i+1][j+1][k+1]*(a-i)*(b-j)*(c-k)
                                + dp[i][j+1][k+1]*i*(b-j)*(c-k)
                                + dp[i+1][j][k+1]*(a-i)*j*(c-k)
                                + dp[i+1][j+1][k]*(a-i)*(b-j)*k
                                + dp[i][j][k+1]*i*j*(c-k)
                                + dp[i][j+1][k]*i*(b-j)*k
                                + dp[i+1][j][k]*(a-i)*j*k;
                    dp[i][j][k]/=(a*b*c-i*j*k);
                }
        printf("%.2lf\n",dp[0][0][0]);
    }
    return 0;
}
