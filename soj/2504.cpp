#include <cstdio>
#include <algorithm>
using namespace std;

struct event
{
    int a,b;
};

int cmp(const event x,const event y)
{
    return (x.b==y.b)? x.a>y.a : x.b<y.b;
}

const int maxn=100000;
int n,i,m,ans;
event e[maxn];

int main()
{
    while (scanf("%d",&n)==1)
    {
        ans=m=0;
        for (i=0;i<n;i++)
        {
            scanf("%d%d",&e[i].a,&e[i].b);
            e[i].b+=e[i].a;
        }
        sort(e,e+n,cmp);
        for (i=0;i<n;i++)
        {
            if (e[i].a>=m)
            {
                ans++;
                m=e[i].b;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}