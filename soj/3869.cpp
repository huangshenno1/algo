#include <cstdio>

int di[4]={0,0,1,-1};
int dj[4]={1,-1,0,0};
char map[1010][1010];
int qi[1000010],qj[1000010],head,tail;
int n;
int ans;

void find(int i,int j)
{
    int ti,tj;
    for (int r=0;r<4;r++)
    {
        ti=i+di[r];
        tj=j+dj[r];
        if (ti>=0 && ti<n && tj>=0 && tj<n && map[ti][tj]=='*')
        {
            map[ti][tj]='.';
            qi[++tail]=ti;
            qj[tail]=tj;
        }
    }
}

void floodfill(int i,int j)
{
    if (map[i][j]=='*')
    {
        ans++;
        map[i][j]='.';
        head=0;
        tail=-1;
        qi[++tail]=i;
        qj[tail]=j;
        while (head <= tail)
        {
            find(qi[head],qj[head]);
            head++;
        }
    }
}

int main()
{
    int i,j;
    while (scanf("%d",&n)==1)
    {
        ans=0;
        for (i=0;i<n;i++)
            scanf("%s",map[i]);
        for (i=0;i<n;i++)
            for (j=0;j<n;j++)
                floodfill(i,j);
        printf("%d\n",ans);
    }
    return 0;
}