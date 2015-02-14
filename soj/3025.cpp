#include <cstdio>
#include <cstring>

int n,m,tot,ans;
char mmp[15];
int mp[105];
int dp[105][65][65];
int dic[65];
int popcount[65];

inline int max(int a, int b) {return a>b?a:b;}

int main()
{
    while (scanf("%d%d",&n,&m)==2)
    {
        tot=0;
        for (int i=0;i<(1<<m);i++)
        {
            if ((i&(i<<1)) || (i&(i<<2))) continue;
            int tmp=i; popcount[tot]=0;
            while (tmp) {popcount[tot]+=(tmp&1); tmp>>=1;}
            dic[tot]=i; tot++;
        }
        for (int i=1;i<=n;i++)
        {
            scanf("%s",mmp);
            mp[i]=0;
            for (int j=0;j<m;j++) mp[i]=mp[i]<<1|(mmp[j]=='H');
        }
        memset(dp,-1,sizeof(dp));
        for (int i=0;i<tot;i++)
        {
            if (dic[i]&mp[1]) continue;
            dp[1][0][i]=popcount[i];
        }
        for (int i=1;i<=n;i++)
            for (int j=0;j<tot;j++)
                for (int k=0;k<tot;k++)
                {
                    if (dic[j]&dic[k]) continue;
                    int x=mp[i]|dic[j]|dic[k];
                    for (int l=0;l<tot;l++)
                    {
                        if (dic[l]&x) continue;
                        if (dp[i-1][j][k]==-1) continue;
                        dp[i][k][l]=max(dp[i][k][l],dp[i-1][j][k]+popcount[l]);
                        //printf("%d %d %d %d\n",i,dic[k],dic[l],dp[i][k][l]);
                    }
                }
        ans=0;
        for (int i=0;i<tot;i++)
            for (int j=0;j<tot;j++)
                ans=max(ans,dp[n][i][j]);
        printf("%d\n",ans);
    }
    return 0;
}
