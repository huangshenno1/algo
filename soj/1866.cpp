#include <cstdio>
#include <cstring>

int f[100010];
int n,m,d[10],i,j,s,ss;

int main()
{
    while (scanf("%d%d",&n,&m)==2)
    {
        memset(f,0,sizeof(f));
        f[0]=-1;
        for (i=0;i<m;i++)
            scanf("%d",&d[i]);
        for (i=1;i<=n;i++)
        {
            s=ss=0;
            for (j=0;j<m;j++)
            {
                if (i>=d[j])
                {
                    ss++;
                    if (f[i-d[j]]==-1)
                    {
                        f[i]=1;
                        break;
                    }
                    s+=f[i-d[j]];
                }
            }
            if (s && s==ss)
                f[i]=-1;
        }
        if (f[n]==1)
            printf("Pablo wins\n");
        else if (f[n]==-1)
            printf("Chris wins\n");
        else
            printf("Draw\n");
    }
    return 0;
}