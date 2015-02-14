#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int T,n;
int e[maxn],a[maxn],b[maxn],d[maxn];
bool vis[maxn];

struct Segment
{
    int l,r;
    bool del;
    void output() {printf("%d-%d",l,r);}
    bool operator < (const Segment s) const
    {
        return (l==s.l&&r>s.r) || l<s.l;
    }
}seg[maxn];
int c;

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        c=0;
        scanf("%d",&n);
        for (int i=1;i<=n;i++) {scanf("%d",&a[i]); d[a[i]]=i;}
        for (int i=1;i<=n;i++) scanf("%d",&b[i]);
        for (int i=1;i<=n;i++) {e[a[i]]=b[i]; vis[i]=0;}
        for (int i=1;i<=n;i++)
        {
            int t=a[i];
            if (vis[t]) continue;
            int p=e[t],m=d[p];
            while (p!=t)
            {
                vis[p]=1;
                p=e[p];
                if (d[p]>m) m=d[p];
            }
            seg[c].l=i; seg[c].r=m; seg[c].del=0; c++;
        }
        sort(seg,seg+c);
        for (int i=1,j=0;i<c;i++)
        {
            if (seg[i].l<=seg[j].r)
            {
                seg[j].r=max(seg[j].r,seg[i].r);
                seg[i].del=1;
            }
            else j=i;
        }
        for (int i=0,first=1;i<c;i++)
        {
            if (!seg[i].del)
            {
                if (!first) printf(" ");
                else first=0;
                seg[i].output();
            }
        }
        printf("\n");
    }
    return 0;
}