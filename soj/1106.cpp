#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int INF = 0x3f3f3f3f;
const int di[]= {0,0,1,-1,1,1,-1,-1}, dj[]= {1,-1,0,0,1,-1,1,-1};
int n,m;
int sti,stj,edi,edj;
int mp[25][25];
char mp2[25][25];

struct Node
{
    int r,c;
    int water;
} t,tt;
queue<Node> Q;
int dp[25][25];

bool valid(int i,int j,int li,int lj)
{
    if (!(i>=1&&i<=n&&j>=1&&j<=m)) return 0;
    if (mp[i][j]==2) return 0;
    if (mp[i][j]==1&&mp[li][lj]==1) return 0;
    return 1;
}

void init()
{
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        {
            if (mp2[i][j]=='u')
                for (int k=i-1; k>0&&mp[k][j]!=2; k--) mp[k][j]=1;
            if (mp2[i][j]=='d')
                for (int k=i+1; k<=n&&mp[k][j]!=2; k++) mp[k][j]=1;
            if (mp2[i][j]=='l')
                for (int k=j-1; k>0&&mp[i][k]!=2; k--) mp[i][k]=1;
            if (mp2[i][j]=='r')
                for (int k=j+1; k<=m&&mp[i][k]!=2; k++) mp[i][k]=1;
        }
}

void solve()
{
    int k,r,c;
    memset(dp,0x3f,sizeof(dp));
    while (!Q.empty()) Q.pop();
    t.r=sti; t.c=stj; t.water=0;
    Q.push(t);
    while (!Q.empty())
    {
        t=Q.front(); Q.pop();
        r=t.r; c=t.c;
        if (t.water>=dp[r][c]) continue;
        dp[r][c]=t.water;
        for (k=0; k<8; k++)
        {
            int nr=r+di[k],nc=c+dj[k];
            if (!valid(nr,nc,r,c)) continue;
            tt.r=nr; tt.c=nc;
            tt.water=t.water+(mp[nr][nc]==1);
            Q.push(tt);
        }
    }
}

int main()
{
    int k,r,c;
    char ch;
    while (scanf("%d%d",&n,&m)==2)
    {
        scanf("%d%d%d%d",&sti,&stj,&edi,&edj);
        memset(mp,0,sizeof(mp));
        memset(mp2,0x01,sizeof(mp2));
        scanf("%d",&k);
        while (k--)
        {
            scanf("%d%d %c",&r,&c,&ch);
            mp2[r][c]=ch;
            mp[r][c]=2;
        }

        init();
        if (mp[sti][stj]>0||mp[edi][edj]>0)
        {
            printf("-1\n");
            continue;
        }
        solve();
        int ans=dp[edi][edj];
        if (ans==INF) ans=-1;
        printf("%d\n",ans);
    }
    return 0;
}
