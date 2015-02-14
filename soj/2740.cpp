#include <stdio.h>

#define MAX 1000000
#define MIN 0

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

struct Node
{
    int l,r;
    int min,max;
}node[200010];

int height[50010];

int Max(int a,int b)
{
    return a>b?a:b;
}

int Min(int a,int b)
{
    return a<b?a:b;
}

void PushUp(int rt)
{
    node[rt].max=Max(node[rt<<1].max,node[rt<<1|1].max);
    node[rt].min=Min(node[rt<<1].min,node[rt<<1|1].min);
}

void Build(int l,int r,int rt)
{
    node[rt].l=l;
    node[rt].r=r;
    if (l==r)
    {
        node[rt].max=node[rt].min=height[l];
        return;
    }
    int m=(l+r)>>1;
    Build(lson);
    Build(rson);
    PushUp(rt);
}

int QurryMin(int L,int R,int l,int r,int rt)
{
    if (L<=l&&R>=r)
        return node[rt].min;
    int m=(l+r)>>1;
    int min=MAX;
    if (L<=m)
        min=Min(QurryMin(L,R,lson),min);
    if (R>m)
        min=Min(QurryMin(L,R,rson),min);
    return min;
}

int QurryMax(int L,int R,int l,int r,int rt)
{
    if (L<=l&&R>=r)
        return node[rt].max;
    int m=(l+r)>>1;
    int max=MIN;
    if (L<=m)
        max=Max(QurryMax(L,R,lson),max);
    if (R>m)
        max=Max(QurryMax(L,R,rson),max);
    return max;
}

int main()
{
    int n,q,i,x,y;
    while (scanf("%d%d",&n,&q)==2)
    {
        for (i=1;i<=n;i++)
            scanf("%d",&height[i]);
        Build(1,n,1);
        for (i=0;i<q;i++)
        {
            scanf("%d%d",&x,&y);
            printf("%d\n",QurryMax(x,y,1,n,1)-QurryMin(x,y,1,n,1));
        }
    }
    return 0;
}