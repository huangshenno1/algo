#include <cstdio>

int m,n;
char map[101][101];
int ans,dis;
int i,j;

int FirstWin(char *str)
{
    int d;
    int b,w;
    for (int k=0;k<n;k++)
    {
        if (str[k]=='b')
            b=k;
        if (str[k]=='w')
            w=k;
    }
    if (w>b)
        d=w-b;
    else d=b-w;
    return d;
}

int main()
{
    while (scanf("%d%d",&m,&n)==2)
    {
        ans=0;
        for (i=0;i<m;i++)
        {
            scanf("%s",map[i]);
            dis=FirstWin(map[i]);
            ans^=dis;
        }
        if (ans)
            printf("mm wins\n");
        else printf("gg wins\n");
    }
    return 0;
}