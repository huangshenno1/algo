#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int n,a[maxn],b[maxn],c[maxn],ans;

int main()
{
    while (scanf("%d",&n)==1)
    {
        for (int i=0;i<n;i++) scanf("%d",&a[i]);
        for (int i=0;i<n;i++) scanf("%d",&b[i]);
        ans=0;
        for (int i=0;i<n;i++) ans=ans^a[i]^b[i];
        for (int i=0;i<n;i++) c[i]=a[i]^ans;
        sort(c,c+n);
        sort(b,b+n);
        bool yes=1;
        for (int i=0;i<n;i++)
            if (c[i]!=b[i]) {yes=0; break;}
        if (yes) printf("%d\n",ans);
        else puts("-1");
    }
    return 0;
}
