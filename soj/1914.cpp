#include <stdio.h>

int max;
char room[30][30];
bool ifReach[30][30];

void Search(int i,int j)
{
    if (room[i-1][j]=='.'&&ifReach[i-1][j]==0)
    {
        ifReach[i-1][j]=1;
        max++;
        Search(i-1,j);
    }
    if (room[i+1][j]=='.'&&ifReach[i+1][j]==0)
    {
        ifReach[i+1][j]=1;
        max++;
        Search(i+1,j);
    }
    if (room[i][j-1]=='.'&&ifReach[i][j-1]==0)
    {
        ifReach[i][j-1]=1;
        max++;
        Search(i,j-1);
    }
    if (room[i][j+1]=='.'&&ifReach[i][j+1]==0)
    {
        ifReach[i][j+1]=1;
        max++;
        Search(i,j+1);
    }
}

int main()
{
    int w,h;
    scanf("%d%d",&w,&h);
    while (w||h)
    {
        max=0;
        for (int i=0;i<=h+1;i++)
        {
            for (int j=0;j<=w+1;j++)
            {
                room[i][j]='#';
                ifReach[i][j]=0;
            }
        }
        for (int i=1;i<=h;i++)
        {
            scanf("%s",room[i]+1);
            room[i][w+1]='#';
        }
        for (int i=1;i<=h;i++)
        {
            for (int j=1;j<=w;j++)
            {
                if (room[i][j]=='@')
                {
                    ifReach[i][j]=1;
                    max++;
                    Search(i,j);
                }
            }
        }
        printf("%d\n",max);
        scanf("%d%d",&w,&h);
    }
    return 0;
}