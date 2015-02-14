#include <cstdio>
#include <cstring>

const int maxn = 32;
const int maxv = 10001;
const int maxs = 320001;
int T,n,s;
int a[maxn],cnt[maxv],bg[maxs];
bool ips;

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        memset(cnt,0,sizeof(cnt));
        ips=0;
        s=0;
        scanf("%d",&n);
        for (int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            cnt[a[i]]++;
            if (cnt[a[i]]>1) ips=1;
            s+=a[i];
        }
        if (ips)
        {
            puts("-1");
            continue;
        }
        memset(bg,0,sizeof(bg));
        bg[0]=1;
        for (int i=0;i<n;i++)
        {
            for (int j=a[i];j<=s;j++)
                bg[j]+=bg[j-a[i]];
            if (bg[a[i]]>1 || bg[s]>1)
            {
                ips=1;
                break;
            }
        }
        if (ips) puts("-1");
        else printf("%d\n",s);
    }
    return 0;
}