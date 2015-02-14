#include <cstdio>

const int maxn = 100010;
int T,n,m,s[maxn];

bool solve(int l)
{
    for (int i=1;i<=n-l+1;i++)
    {
        int r=l-(s[i+l-1]-s[i-1]);
        if (r<=m) return 1;
    }
    return 0;
}

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&m);
        s[0]=0;
        for (int temp,i=1;i<=n;i++)
        {
            scanf("%d",&temp);
            s[i]=s[i-1]+temp;
        }
        int low=1,high=n,mid;
        while (low<=high)
        {
            mid=(low+high)>>1;
            if (solve(mid)) low=mid+1;
            else high=mid-1;
        }
        printf("%d\n",high);
    }
    return 0;
}