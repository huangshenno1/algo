#include <cstdio>
#include <cstring>

int n,k;
int a[210];
int s[210][210],p[210][210];
int iCase=1;

int Abs(int x)
{
    return x>0?x:-x;
}

void Init()
{
    for (int i=1;i<=n;i++)
    {
        for (int j=i;j<=n;j++)
        {
            p[i][j]=0;
            int t=(i+j)/2;
            for (int x=i;x<=j;x++)
                p[i][j]+=Abs(a[x]-a[t]);
        }
    }
    for (int i=1;i<=n;i++)
    {
        s[i][1]=p[1][i];
    }
}

void Solve()
{
    for (int j=2;j<=k;j++)
    {
        for (int i=j;i<=n;i++)
        {
            s[i][j]=s[j-1][j-1]+p[j][i];
            for (int x=j+1;x<=i;x++)
            {
                if (s[i][j]>s[x-1][j-1]+p[x][i])
                    s[i][j]=s[x-1][j-1]+p[x][i];
            }
        }
    }
}

int main()
{
    while (scanf("%d%d",&n,&k)==2 && n)
    {
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        Init();
        Solve();
        printf("Chain %d\n",iCase++);
        printf("Total distance sum = %d\n\n",s[n][k]);
    }
    return 0;
}