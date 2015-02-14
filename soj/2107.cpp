#include <cstdio>
#include <cstring>

int s,n;
char a[15][1000];
bool vis[11];

void Ban(char num[])
{
    for (int i=0;num[i]!='\0';i++)
        vis[num[i]-'0']=1;
}

int Judge(int i,int j)
{
    memset(vis,0,sizeof(vis));
    int k;
    for (k=1;k<=s;k++) 
    {
        if (a[i][j+k]=='-')
            Ban("14");
        if (a[i][j+k]==' '||a[i][j+k]==0)
            Ban("02356789");
    }

    for (k=1;k<=s;k++) 
    {
        if (a[i+k][j]=='|')
            Ban("1237");
        if (a[i+k][j]==' '||a[i+k][j]==0)
            Ban("045689");
    }

    for (k=1;k<=s;k++) 
    {
        if (a[i+k][j+s+1]=='|')
            Ban("56");
        if (a[i+k][j+s+1]==' '||a[i+k][j+s+1]==0)
            Ban("01234789");
    }

    for (k=1;k<=s;k++) 
    {
        if (a[i+s+1][j+k]=='-')
            Ban("017");
        if (a[i+s+1][j+k]==' '||a[i+s+1][j+k]==0)
            Ban("2345689");
    }

    for (k=1;k<=s;k++) 
    {
        if (a[i+s+1+k][j]=='|')
            Ban("134579");
        if (a[i+s+1+k][j]==' '||a[i+s+1+k][j]==0)
            Ban("0268");
    }

    for (k=1;k<=s;k++) 
    {
        if (a[i+s+1+k][j+s+1]=='|')
            Ban("2");
        if (a[i+s+1+k][j+s+1]==' '||a[i+s+1+k][j+s+1]==0)
            Ban("013456789");
    }

    for (k=1;k<=s;k++) 
    {
        if (a[i+2*s+2][j+k]=='-')
            Ban("147");
        if (a[i+2*s+2][j+k]==' '||a[i+2*s+2][j+k]==0)
            Ban("0235689");
    }

    for (k=0;k<=9;k++)
    {
        if (vis[k]==0)
            return k;
    }
    return -1;
}

int main()
{
    int i,t;
    while (~scanf("%d%d",&s,&n) && n)
    {
        getchar();
        for (i=0;i<2*s+3;i++)
            gets(a[i]);
        for (i=0;i<(s+3)*n-1;i+=s+3)
        {
            t=Judge(0,i);
            if (t==-1)
                printf("*");
            else printf("%d",t);
        }
        printf("\n");
    }
    return 0;
}