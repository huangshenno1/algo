#include <cstdio>
#include <algorithm>
using namespace std;
const int INF=0x7fffffff;
const int maxn=100010;

struct Node
{
    int x,y,dis;
};

bool cmpx(const Node a,const Node b)
{
    return a.x<b.x;
}

bool cmpy(const Node a,const Node b)
{
    return a.y<b.y;
}

bool cmpd(const Node a,const Node b)
{
    return a.dis<b.dis;
}

int n,ans,sx,sy,i;
Node a[maxn];

int main()
{
    while (scanf("%d",&n)==1)
    {
        ans=INF;
        sx=sy=0;
        for (i=0;i<n;i++)
        {
            scanf("%d%d",&a[i].x,&a[i].y);
            a[i].dis=0;
            sx+=a[i].x;
            sy+=a[i].y;
        }

        sort(a,a+n,cmpx);
        for (i=0;i<n;i++)
        {
            a[i].dis+=sx-a[i].x*(n-2*i);
            sx-=2*a[i].x;
        }

        sort(a,a+n,cmpy);
        for (i=0;i<n;i++)
        {
            a[i].dis+=sy-a[i].y*(n-2*i);
            ans=min(ans,a[i].dis);
            sy-=2*a[i].y;
        }

        printf("%d\n",ans);
    }
    return 0;
}