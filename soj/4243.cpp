#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
int n,m;
char mapp[110][110];
int g[110][110];
int h[110][110];
bool vis[110][110];
queue<int> qi,qj;

void bfs(int i,int j)
{
    int ti,tj;
    vis[i][j]=0;
    for (int r=0;r<4;r++)
    {
        ti=i+dy[r],tj=j+dx[r];
        if (mapp[ti][tj]!='.')
            continue;
        if (h[ti][tj]>=h[i][j]-g[ti][tj])
            continue;
        h[ti][tj]=h[i][j]-g[ti][tj];
        if (h[n][n]>0)
            return;
        if (!vis[ti][tj])
        {
            qi.push(ti);
            qj.push(tj);
            vis[ti][tj]=1;
        }
    }
}

int main()
{
    int i,j,k,r,ti,tj;
    while (scanf("%d%d",&n,&m)==2)
    {
        if (n<=0)
        {
            printf("Die..\n");
            continue;
        }
        while (!qi.empty())
            qi.pop();
        while (!qj.empty())
            qj.pop();
        for (i=0;i<=n+1;i++)
        {
            for (j=0;j<=n+1;j++)
            {
                mapp[i][j]='#';
                h[i][j]=0;
                g[i][j]=0;
                vis[i][j]=0;
            }
        }
        for (i=1;i<=n;i++)
        {
            scanf("%s",mapp[i]+1);
            mapp[i][n+1]='#';
        }
        for (i=1;i<=n;i++)
        {
            for (j=1;j<=n;j++)
            {
                if (mapp[i][j]=='G')
                {
                    for (r=0;r<4;r++)
                    {
                        for (k=1;k<=1;k++)
                        {
                            ti=i+dy[r]*k,tj=j+dx[r]*k;
                            if (ti>0&&ti<=n&&tj>0&&tj<=n)
                                g[ti][tj]+=1;
                        }
                    }
                }
                if (mapp[i][j]=='M')
                {
                    for (r=0;r<4;r++)
                    {
                        for (k=1;k<=2;k++)
                        {
                            ti=i+dy[r]*k,tj=j+dx[r]*k;
                            if (ti>0&&ti<=n&&tj>0&&tj<=n)
                                g[ti][tj]+=3;
                        }
                    }
                }
                if (mapp[i][j]=='F')
                {
                    for (r=0;r<4;r++)
                    {
                        for (k=1;k<=3;k++)
                        {
                            ti=i+dy[r]*k,tj=j+dx[r]*k;
                            if (ti>0&&ti<=n&&tj>0&&tj<=n)
                                g[ti][tj]+=5;
                        }
                    }
                }
            }
        }
        h[1][1]=m-g[1][1];
        qi.push(1),qj.push(1);
        while (!qi.empty())
        {
            ti=qi.front();qi.pop();
            tj=qj.front();qj.pop();
            bfs(ti,tj);
        }
        if (h[n][n]>0)
            printf("Girl~\n");
        else printf("Die..\n");
    }
    return 0;
}