#include <cstdio>

const int maxn = 100010;

int n;
int a[maxn];
long long sum[maxn];
int l[maxn],r[maxn];

struct node
{
    int s,no;
}stack[maxn];
int top;
long long temp,ans;

int main()
{
    int i;
    while (scanf("%d",&n)==1)
    {
        for (i=1;i<=n;i++) scanf("%d",&a[i]);
        for (sum[0]=0,i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];

        stack[0].s=-0x3fffffff;
        stack[0].no=0;
        top=1;
        for (i=1;i<=n;i++)
        {
            while (a[i]<=stack[top-1].s) top--;
            l[i]=stack[top-1].no;
            stack[top].s=a[i];
            stack[top].no=i;
            top++;
        }

        stack[0].s=-0x3fffffff;
        stack[0].no=n+1;
        top=1;
        for (i=n;i>=1;i--)
        {
            while (a[i]<=stack[top-1].s) top--;
            r[i]=stack[top-1].no;
            stack[top].s=a[i];
            stack[top].no=i;
            top++;
        }

        for (ans=0,i=1;i<=n;i++)
        {
            temp=a[i]*(sum[r[i]-1]-sum[l[i]]);
            if (temp>ans) ans=temp;
        }
        printf("%lld\n",ans);
    }
    return 0;
}