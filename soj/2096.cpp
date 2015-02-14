#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100;
int T,m,n,ans,i,j,l,r;
int a[maxn][maxn],up[maxn][maxn],left[maxn][maxn],right[maxn][maxn];

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        ans=0;
        scanf("%d%d",&n,&m);
        for (i=0;i<n;i++)
            for (j=0;j<m;j++)
                scanf("%d",&a[i][j]);
        for (i=0;i<n;i++)
        {
            l=-1,r=m;
            for (j=0;j<m;j++)
            {
                if (a[i][j]==1)
                {
                    up[i][j]=left[i][j]=0;
                    l=j;
                }
                else
                {
                    up[i][j]= (i==0)?1:up[i-1][j]+1;
                    left[i][j]= (i==0)?l+1:max(left[i-1][j],l+1);
                }
            }
            for (j=m-1;j>=0;j--)
            {
                if (a[i][j]==1)
                {
                    right[i][j]=n;
                    r=j;
                }
                else
                {
                    right[i][j]= (i==0)?r-1:min(right[i-1][j],r-1);
                    ans=max(ans,up[i][j]*(right[i][j]-left[i][j]+1));
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}