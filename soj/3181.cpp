#include <cstdio>
#include <algorithm>
using namespace std;

int T,n;
int degree[1010],sum;
bool ans;

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        ans=1;
        sum=0;
        scanf("%d",&n);
        for (int i=0;i<n;i++)
        {
            scanf("%d",degree+i);
            if (degree[i]>=n) ans=0;
            sum+=degree[i];
        }
        if (sum%2==1) ans=0;
        if (ans)
        {
            int l=0,r=n-1;
            while (1)
            {
                sort(degree+l,degree+r+1);
                while (degree[l]==0) l++;
                if (l>=r) break;
                if (degree[r]>r-l) {ans=0; break;}
                for (int i=r-1,j=0;j<degree[r];i--,j++) degree[i]--;
                r--;
            }
            if (l==r && degree[l]>0) ans=0;
        }
        if (ans) puts("YES");
        else puts("NO");
    }
    return 0;
}