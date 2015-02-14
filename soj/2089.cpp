#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

const double INF = 1e300;

int x[10],y[10];
double dis[10][10];
double dp[256][8];
double ans;

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        for (int i=0;i<10;i++) scanf("%d%d",&x[i],&y[i]);

        for (int i=0;i<10;i++)
            for (int j=0;j<10;j++)
                dis[i][j]=sqrt((double)((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])));

        for (int i=0;i<256;i++)
            for (int j=0;j<8;j++)
                dp[i][j]=INF;

        queue<int> Q;
        for (int i=0;i<8;i++)
        {
            dp[1<<i][i]=dis[1][i+2];
            Q.push((1<<i)*8+i);
        }
        while (!Q.empty())
        {
            int i=Q.front()/8;
            int j=Q.front()%8;
            for (int k=0;k<8;k++)
            {
                if (i&(1<<k)) continue;
                if (dp[i|(1<<k)][k]>dp[i][j]+dis[j+2][k+2])
                {
                    dp[i|(1<<k)][k]=dp[i][j]+dis[j+2][k+2];
                    Q.push((i|(1<<k))*8+k);
                }
            }
            Q.pop();
        }

        ans=INF;
        for (int i=0;i<8;i++)
        {
            if (ans>dp[255][i]+dis[0][i+2])
                ans=dp[255][i]+dis[0][i+2];
        }
        printf("%.3lf\n",ans+dis[0][1]);
    }
    return 0;
}