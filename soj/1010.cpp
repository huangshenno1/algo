#include <cstdio>
#include <cstring>

const int dx[4]={1,0,-1,0};
const int dy[4]={0,-1,0,1};
const char dir[4]={'E','S','W','N'};

int m,n;
int x,y,d;
char ch_d;
char cmd[110];
bool out;
bool lost[60][60];

void init()
{
    out=0;
    if (ch_d=='E')
        d=0;
    if (ch_d=='S')
        d=1;
    if (ch_d=='W')
        d=2;
    if (ch_d=='N')
        d=3;
}

void output()
{
    printf("%d %d %c",x,y,dir[d]);
    if (out) printf(" LOST");
    printf("\n");
}

void check()
{
    if (x<0 || x>m || y<0 || y>n)
    {
        x-=dx[d];
        y-=dy[d];
        if (lost[y][x])
            return;
        lost[y][x]=1;
        out=1;
    }
}

void go(char c)
{
    if (c=='F')
    {
        x+=dx[d];
        y+=dy[d];
        check();
    }
    if (c=='R')
        d=(d+1)%4;
    if (c=='L')
        d=(d+3)%4;
}

int main()
{
    scanf("%d%d",&m,&n);
    memset(lost,0,sizeof(lost));
    while (scanf("%d %d %c",&x,&y,&ch_d)!=EOF)
    {
        getchar();
        scanf("%s",cmd);
        init();
        for (int i=0;cmd[i]!='\0';i++)
        {
            go(cmd[i]);
            if (out)
                break;
        }
        output();
    }
    return 0;
}