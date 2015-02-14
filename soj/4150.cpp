#include <cstdio>
#include <cstring>

int n;
int h[110];
int a[110],b[110];
int ans;

int main()
{
    int i,j;
    while (~scanf("%d",&n))
    {
        for (i=0;i<n;i++)
            scanf("%d",&h[i]);
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        ans=0;
        for (i=n-2;i>=0;i--)
        {
            for (j=i+1;j<n;j++)
            {
                if (h[i]>h[j] && a[i]<=a[j])
                    a[i]=a[j]+1;
            }
        }
        for (i=1;i<n;i++)
        {
            for (j=i-1;j>=0;j--)
            {
                if (h[i]>h[j] && b[i]<=b[j])
                    b[i]=b[j]+1;
            }
        }
        for (i=0;i<n;i++)
        {
            if (ans<a[i]+b[i])
                ans=a[i]+b[i];
        }
        ans++;
        printf("%d\n",n-ans);
    }
    return 0;
}