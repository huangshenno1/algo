#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int dx[8]={1,1,2,2,-1,-1,-2,-2};
const int dy[8]={2,-2,1,-1,2,-2,1,-1};
int f[8][8];
int sx,sy,ex,ey;
queue<int> Q;

bool in(int i,int j)
{
    if (i<0 || i>7 || j<0 ||j>7) return 0;
    return 1;
}

void solve()
{
    memset(f,-1,sizeof(f));
    f[sx][sy]=0;
    while (!Q.empty()) Q.pop();
    Q.push(sx*8+sy);
    while (!Q.empty())
    {
        int temp=Q.front(); Q.pop();
        int x=temp/8, y=temp%8;
        for (int d=0;d<8;d++)
        {
            int nx=x+dx[d], ny=y+dy[d];
            if (in(nx,ny) && f[nx][ny]==-1)
            {
                f[nx][ny]=f[x][y]+1;
                if (nx==ex && ny==ey) return;
                Q.push(nx*8+ny);
            }
        }
    }
}

int main()
{
    char str1[5],str2[5];
    while (scanf("%s%s",str1,str2)==2)
    {
        sx=str1[0]-'a'; sy=str1[1]-'1';
        ex=str2[0]-'a'; ey=str2[1]-'1';
        solve();
        printf("To get from %s to %s takes %d knight moves.\n",str1,str2,f[ex][ey]);
    }
    return 0;
}