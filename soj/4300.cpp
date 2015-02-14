#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
const ll INF = 1000000000000LL;
const int mod = 1000000007;
const int maxn = 150;
const double eps = 1e-6;
const double PI = acos(-1.0);

int n;
int a[3][maxn];
struct Node
{
    int id;
    int value;
    bool operator<(const Node &o) const {return value<o.value;}
}b[3][maxn];
ll dp[maxn][maxn][maxn];

inline bool inside(int i,int j,int k,int index)
{
    return a[0][index]<=b[0][i].value && a[1][index]<=b[1][j].value && a[2][index]<=b[2][k].value;
}

inline ll distance(int i,int j,int k,int index)
{
    return (ll)b[0][i].value-(ll)a[0][index]+(ll)b[1][j].value-(ll)a[1][index]+(ll)b[2][k].value-(ll)a[2][index];
}

int main()
{
    while (scanf("%d",&n)==1)
    {
        for (int i=0;i<3;i++)
        {
            for (int j=0;j<n;j++)
            {
                scanf("%d",&a[i][j]);
                b[i][j].id=j;
                b[i][j].value=a[i][j];
            }
            sort(b[i],b[i]+n);
        }
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                for (int k=0;k<n;k++)
                    dp[i][j][k]=INF;;
        dp[0][0][0]=0;
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                for (int k=0;k<n;k++)
                {
                    if (i+1<n)
                    {
                        if (inside(i+1,j,k,b[0][i+1].id))
                            dp[i+1][j][k]=min(dp[i+1][j][k],dp[i][j][k]+distance(i+1,j,k,b[0][i+1].id));
                        else dp[i+1][j][k]=min(dp[i+1][j][k],dp[i][j][k]);
                    }
                    if (j+1<n)
                    {
                        if (inside(i,j+1,k,b[1][j+1].id))
                            dp[i][j+1][k]=min(dp[i][j+1][k],dp[i][j][k]+distance(i,j+1,k,b[1][j+1].id));
                        else dp[i][j+1][k]=min(dp[i][j+1][k],dp[i][j][k]);
                    }
                    if (k+1<n)
                    {
                        if (inside(i,j,k+1,b[2][k+1].id))
                            dp[i][j][k+1]=min(dp[i][j][k+1],dp[i][j][k]+distance(i,j,k+1,b[2][k+1].id));
                        else dp[i][j][k+1]=min(dp[i][j][k+1],dp[i][j][k]);
                    }
                }
        printf("%lld\n",dp[n-1][n-1][n-1]);
    }
    return 0;
}
