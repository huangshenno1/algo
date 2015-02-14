#include <cstdio>
#include <algorithm>
using namespace std;

int h[5010];

struct Segment
{
    int a,b;
    bool operator < (const Segment &s) const
    {
        return a==s.a&&b<s.b || a<s.a;
    }
    bool operator != (const Segment &s)const
    {
        return a!=s.a||b!=s.b;
    }
}seg[10010];

struct Segment2
{
    int st;
    bool fromleft;
    bool operator < (const Segment2 &t) const
    {
        return (st==t.st) ? fromleft : st<t.st;
    }
}seg2[20010];

int main()
{
    int n,m,maxk,maxh;
    int a,b,c,flag,l,d;
    while (scanf("%d%d%d%d",&n,&maxk,&maxh,&m)==4)
    {
        for (int i=1;i<=n;i++) h[i]=maxh;
        for (int i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            if (a>b) swap(a,b);
            seg[i].a=a; seg[i].b=b;
        }
        sort(seg,seg+m);

        c=0;
        for (int i=1;i<m;i++) {if (seg[i]!=seg[c] && seg[i].b-seg[i].a>1) seg[++c]=seg[i];}
        m=c+1;

        c=0;
        for (int i=0;i<m;i++)
        {
            seg2[c].st=seg[i].a+1; seg2[c].fromleft=1; c++;
            seg2[c].st=seg[i].b-1; seg2[c].fromleft=0; c++;
        }
        sort(seg2,seg2+c);

        l=1; d=0;
        for (int i=0;i<c;i++)
        {
            if (seg2[i].st>l) {while(seg2[i].st>l) {h[l]-=d; l++;}}
            if (seg2[i].fromleft) d++;
            else
            {
                while(seg2[i].st>=l) {h[l]-=d; l++;}
                d--;
            }
        }

        for (int i=1;i<=n;i++) printf("%d\n",h[i]);
    }
    return 0;
}