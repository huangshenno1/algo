#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 0x7fffffff;
const int maxn = 50005;
int T,n,sum,k,ans,ans1,ans2;
int a[maxn];
int l[maxn],r[maxn];

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        sum=k=0;
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
            if (a[i]>0) k++;
        }

        if (k<=2)
        {
            ans1=ans2=-INF;
            for (int i=1;i<=n;i++)
            {
                if (a[i]>ans2) ans2=a[i];
                if (ans2>ans1) swap(ans1,ans2);
            }
            printf("%d\n",ans1+ans2);
            continue;
        }

        l[0]=0;
        for (int i=1;i<=n;i++) l[i]=max(l[i-1],0)+a[i];
        for (int i=1;i<=n;i++) l[i]=max(l[i-1],l[i]);
        r[n+1]=0;
        for (int i=n;i>=1;i--) r[i]=max(r[i+1],0)+a[i];
        for (int i=n;i>=1;i--) r[i]=max(r[i+1],r[i]);
        ans1=-INF;
        for (int i=1;i<=n;i++)
            if (l[i]+r[i+1]>ans1) ans1=l[i]+r[i+1];

        for (int i=1;i<=n;i++) a[i]=-a[i];
        l[0]=0;
        for (int i=1;i<=n;i++) l[i]=max(l[i-1],0)+a[i];
        for (int i=1;i<=n;i++) l[i]=max(l[i-1],l[i]);
        r[n+1]=0;
        for (int i=n;i>=1;i--) r[i]=max(r[i+1],0)+a[i];
        for (int i=n;i>=1;i--) r[i]=max(r[i+1],r[i]);
        ans2=-INF;
        for (int i=1;i<=n;i++)
            if (l[i]+r[i+1]>ans2) ans2=l[i]+r[i+1];
        ans2=sum+ans2;

        ans=max(ans1,ans2);
        printf("%d\n",ans);
    }
    return 0;
}