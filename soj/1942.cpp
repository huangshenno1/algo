#include <cstdio>

const int maxn = 15;
int T,cas=1,n,k,ans,cnt;
int a[maxn],b[maxn];

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&k);
        b[0]=1;
        for (int i=1;i<k;i++) b[i]=b[i-1]*(n-k+i);
        for (int i=k;i>=1;i--) scanf("%d",&a[i]);
        ans=1;
        for (int i=k;i>=1;i--)
        {
            cnt=a[i]-1;
            for (int j=k;j>i;j--)
                if (a[j]<a[i]) cnt--;
            ans+=cnt*b[i-1];
        }
        printf("Variace cislo %d ma poradove cislo %d.\n",cas++,ans);
    }
    return 0;
}
