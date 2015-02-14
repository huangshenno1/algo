#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

const int maxn = 1010;
int n;
int a[maxn],ans;

int main()
{
    int i,j,k;
    while (scanf("%d",&n)==1 && n)
    {
        for (i=0;i<n;i++) scanf("%d",&a[i]);
        sort(a,a+n);
        ans=-1;
        for (k=n-1;k>=2;k--)
        {
            i=0; j=k-1;
            while (i<j)
            {
                if (a[i]+a[j]<a[k]) i++;
                else if (a[i]+a[j]>a[k]) j--;
                else if (ans<a[k]) ans=a[k],i++;
            }
            if (ans>-1) break;
        }
        printf("%d\n",ans);
    }
    return 0;
}
