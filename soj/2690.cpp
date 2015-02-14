#include <cstdio>

const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};

int n,m;
char map[1010][1010];
int ans;

void dfs(int i,int j)
{
    int r,ni,nj;
    if (map[i][j]=='*')
        ans++;
    map[i][j]='#';
    for (r=0;r<4;r++)
    {
        ni=i+di[r];
        nj=j+dj[r];
        if (map[ni][nj]!='#')
            dfs(ni,nj);
    }
}

int main()
{
    int i,j;
    bool flag;
    while (scanf("%d%d",&n,&m)==2)
    {
        flag=0;
        for (i=1;i<=n;i++)
            scanf("%s",map[i]+1);
        for (i=1;i<=n;i++)
            map[i][0]=map[i][m+1]='#';
        for (i=1;i<=m;i++)
            map[0][i]=map[n+1][i]='#';
        ans=0;
        for (i=1;i<=n;i++)
        {
            for (j=1;j<=m;j++)
            {
                if (map[i][j]=='X')
                {
                    dfs(i,j);
                    flag=1;
                    break;
                }
            }
            if (flag)
                break;
        }
        printf("%d\n",ans);
    }
}