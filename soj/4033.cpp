#include <cstdio>
#include <cstring>

const int INF = 0x3fffffff;
const int maxn = 100010;
int T=1,n,a[maxn][3],dp[maxn][3];

inline int Min(int a,int b) {return a<b?a:b;}
inline int Min(int a,int b,int c) {return Min(Min(a,b),c);}
inline int Min(int a,int b,int c,int d) {return Min(Min(a,b),Min(c,d));}

int main()
{
    while (~scanf("%d",&n) && n)
    {
        for (int i=0;i<n;i++)
            for (int j=0;j<3;j++)
                scanf("%d",&a[i][j]);
        dp[0][0]=INF; dp[0][1]=a[0][1]; dp[0][2]=a[0][1]+a[0][2];
        for (int i=1;i<n;i++)
        {
            dp[i][0]=a[i][0]+Min(dp[i-1][0],dp[i-1][1]);
            dp[i][1]=a[i][1]+Min(dp[i-1][0],dp[i-1][1],dp[i-1][2],dp[i][0]);
            dp[i][2]=a[i][2]+Min(dp[i-1][1],dp[i-1][2],dp[i][1]);
        }
        printf("%d. %d\n",T++,dp[n-1][1]);
    }
    return 0;
}