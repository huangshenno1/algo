#include <stdio.h>

int r,c;
char map[20][20];
char cmd[60];
int i,j,k;
int di,dj;
int iCase=1;
bool flag;

bool Judge()
{
    int i,j;
    for (i=1;i<r-1;i++)
    {
        for (j=1;j<c-1;j++)
        {
            if (map[i][j]=='b'||map[i][j]=='+'||map[i][j]=='W')
            {
                return 0;
            }
        }
    }
    return 1;
}

void Go()
{
    if (map[i+di][j+dj]=='.'||map[i+di][j+dj]=='+')
    {
        if (map[i][j]=='w')
        {
            map[i][j]='.';
        }
        else map[i][j]='+';
        i+=di;
        j+=dj;
        if (map[i][j]=='.')
            map[i][j]='w';
        else map[i][j]='W';
    }
    else if ((map[i+di][j+dj]=='b'||map[i+di][j+dj]=='B')&&(map[i+di+di][j+dj+dj]=='.'||map[i+di+di][j+dj+dj]=='+'))
    {
        if (map[i][j]=='w')
        {
            map[i][j]='.';
        }
        else map[i][j]='+';
        i+=di;
        j+=dj;
        if (map[i][j]=='b')
            map[i][j]='w';
        else map[i][j]='W';
        if (map[i+di][j+dj]=='.')
            map[i+di][j+dj]='b';
        else map[i+di][j+dj]='B';
    }
}

int main()
{
    while (scanf("%d%d",&r,&c)==2 && r)
    {
        for (i=0;i<r;i++)
            scanf("%s",map[i]);
        scanf("%s",cmd);
        for (i=1;i<r-1;i++)
        {
            flag=0;
            for (j=1;j<c-1;j++)
            {
                if (map[i][j]=='w'||map[i][j]=='W')
                {
                    flag=1;
                    break;
                }
            }
            if (flag)
                break;
        }
        for (k=0;cmd[k]!='\0';k++)
        {
            di=dj=0;
            if (cmd[k]=='L')
                dj=-1;
            else if (cmd[k]=='R')
                dj=1;
            else if (cmd[k]=='U')
                di=-1;
            else if (cmd[k]=='D')
                di=1;
            Go();
            flag=Judge();
            if (flag)
                break;
        }
        

        printf("Game %d: ",iCase++);
        if (flag)
            printf("complete\n");
        else printf("incomplete\n");
        for (i=0;i<r;i++)
        {
            printf("%s\n",map[i]);
        }
    }
    return 0;
}