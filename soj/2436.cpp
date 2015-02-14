#include <stdio.h>

#define MAX 1000000000
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

struct Node
{
    int l,r;
    int min;
}node[120010];

int time[30010];

int Min(int a,int b)
{
    return a<b?a:b;
}

void PushUp(int rt)
{
    node[rt].min=Min(node[rt<<1].min,node[rt<<1|1].min);
}

void Build(int l,int r,int rt)
{
    node[rt].l=l;
    node[rt].r=r;
    if (l==r)
    {
        node[rt].min=time[l];
        return;
    }
    int m=(l+r)>>1;
    Build(lson);
    Build(rson);
    PushUp(rt);
}

int Qurry(int L,int R,int l,int r,int rt)
{
    if (L<=l&&R>=r)
        return node[rt].min;
    int m=(l+r)>>1;
    int ret=MAX;
    if (L<=m)
        ret=Min(Qurry(L,R,lson),ret);
    if (R>m)
        ret=Min(Qurry(L,R,rson),ret);
    return ret;
}

int main()
{
    int t,n,m,i,x,y;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        for (i=1;i<=n;i++)
            scanf("%d",&time[i]);
        Build(1,n,1);
        scanf("%d",&m);
        for (i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            printf("%d\n",Qurry(x,y,1,n,1));
        }
    }
    return 0;
}