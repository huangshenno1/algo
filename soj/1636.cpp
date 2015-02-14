#include <cstdio>

const int x[]={1,-1,0,0};
const int y[]={0,0,1,-1};

int n;
char map[6][6];
int max;
int count;

bool Place(int i,int j)
{
    int ti,tj;
    int dir;
    if (map[i][j]=='.')
    {
        for (dir=0;dir<4;dir++)
        {
            ti=i;
            tj=j;
            while (1)
            {
                if (map[ti][tj]=='O')
                    return 0;
                if (map[ti][tj]=='X')
                    break;
                ti+=y[dir];
                tj+=x[dir];
            }
        }
        return 1;
    }
    return 0;
}

void Search()
{
    int i,j;
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            if (Place(i,j))
            {
                map[i][j]='O';
                count++;
                if (count>max)
                    max=count;

                Search();

                map[i][j]='.';
                count--;
            }
        }
    }
}

int main()
{
    int i,j;
    while (scanf("%d",&n)==1 && n)
    {
        for (i=0;i<6;i+=n+1)
            for (j=0;j<6;j++)
                map[i][j]='X';
        for (i=1;i<=n;i++)
        {
            scanf("%s",map[i]+1);
            map[i][0]='X';
            map[i][n+1]='X';
        }
        max=count=0;
        
        Search();

        printf("%d\n",max);
    }
    return 0;
}