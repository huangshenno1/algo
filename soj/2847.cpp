#include <cstdio>

const int INF = 100000;
const int maxn = 50005;
int t,n;
int a[maxn],cnt[maxn],ans;

int find(int x)
{
    int low=0,high=ans,mid;
    while (low<=high)
    {
        mid=(low+high)/2;
        if (cnt[mid]>x) high=mid-1;
        else if (cnt[mid+1]<=x) low=mid+1;
        else return mid+1;
    }
    return mid+1;
}

int main()
{
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        ans=0; cnt[0]=0;
        for (int i=1;i<=n;i++) cnt[i]=INF;
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        
        for (int i=1;i<=n;i++)
        {
            int d=find(a[i]);
            if (cnt[d]>a[i]) cnt[d]=a[i];
            if (d>ans) ans=d;
        }
        printf("%d\n",ans);
    }
    return 0;
}