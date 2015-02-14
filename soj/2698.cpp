#include <cstdio>
#include <cstring>

const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};

int m,n;
char map[51][51];
bool b[51][51];
char str[51];
int cmd[51],len_cmd;
int ans;
int ci,cj,ni,nj;

int main()
{
    int t;
    int i,j;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%d",&m,&n);
        for (i=0;i<m;i++)
            scanf("%s",map[i]);
        scanf("%s",str);
        len_cmd=strlen(str);
        for (i=0;str[i]!='\0';i++)
        {
            if (str[i]=='S')
                cmd[i]=0;
            else if (str[i]=='N')
                cmd[i]=1;
            else if (str[i]=='E')
                cmd[i]=2;
            else cmd[i]=3;
        }
        memset(b,0,sizeof(b));
        ans=0;
        ci=cj=0;
        while (b[ci][cj]==0)
        {
            b[ci][cj]=1;
            for (i=0;i<len_cmd;i++)
            {
                ni=ci+di[cmd[i]];
                nj=cj+dj[cmd[i]];
                if (ni==-1)
                    ni=m-1;
                if (ni==m)
                    ni=0;
                if (nj==-1)
                    nj=n-1;
                if (nj==n)
                    nj=0;
                if (map[ni][nj]=='#')
                    continue;
                if (map[ni][nj]=='T')
                {
                    ans++;
                    map[ni][nj]='.';
                }
                ci=ni;
                cj=nj;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}