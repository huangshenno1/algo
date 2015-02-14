#include <cstdio>
#include <algorithm>
using namespace std;

int n,l,ans,i,j;
char a[1010][2010];
int f[1010][2010];

int main()
{
    while (scanf("%d",&n)==1 && n)
    {
        getchar();
        l=2*n;
        for (i=0;i<=l;i++)
            f[0][i]=0;
        ans=0;
        for (i=1;i<=n;i++)
        {
            gets(a[i]+1);
            for (j=i;j<=l-i;j+=2)
            {
                if (a[i][j]=='X')
                    f[i][j]=0;
                else if (f[i-1][j]==1)
                    f[i][j]=min(f[i-1][j-1],f[i-1][j+1])+1;
                else f[i][j]=1;
                ans=max(ans,f[i][j]);
            }
            for (j=i+1;j<=l-i-1;j+=2)
            {
                f[i][j]= (a[i][j]=='X')?0:1;
                ans=max(ans,f[i][j]);
            }
        }
        printf("%d\n",ans*ans);
    }
    return 0;
}