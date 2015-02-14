#include <cstdio>
#include <algorithm>
using namespace std;

int T=1,n,ans,sz,f[100];
struct BLOCK
{
    int x,y,h;
    int no;
    bool operator < (const BLOCK &b) const
    {
        return x==b.x ? y<b.y : x<b.x;
    }
}block[100];

int main()
{
    int t[3],i,j;
    while (scanf("%d",&n)==1 && n)
    {
        sz=0;
        for (i=0;i<n;i++)
        {
            scanf("%d%d%d",&t[0],&t[1],&t[2]);
            sort(t,t+3);
            block[sz].no=i; block[sz].x=t[0]; block[sz].y=t[1]; block[sz].h=t[2]; sz++;
            block[sz].no=i; block[sz].x=t[0]; block[sz].y=t[2]; block[sz].h=t[1]; sz++;
            block[sz].no=i; block[sz].x=t[1]; block[sz].y=t[2]; block[sz].h=t[0]; sz++;
        }
        sort(block, block+sz);
        for (i=0;i<sz;i++) f[i]=block[i].h;
        for (i=sz-1;i>=0;i--)
        {
            for (j=i+1;j<sz;j++)
            {
                if (block[i].x<block[j].x && block[i].y<block[j].y && f[i] < f[j]+block[i].h)
                    f[i]=f[j]+block[i].h;
            }
        }
        ans=0;
        for (i=0;i<sz;i++) ans=max(ans,f[i]);
        printf("Case %d: maximum height = %d\n",T++,ans);
    }
    return 0;
}
