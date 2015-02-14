#include <stdio.h>

#define MAX 2000000000
#define N 302

typedef struct
{
    int l,r;
    int min;
}Node;

struct mtree
{
    int l,r;
    Node node[4*N];
}tree[4*N];

int num[N][N];
int minimum;

int Min(int a,int b)
{
    return a<b?a:b;
}

void CBuild(int rt,int step,int l,int r,int k)
{
    tree[rt].node[step].l=l;
    tree[rt].node[step].r=r;
    if (l==r)
    {
        tree[rt].node[step].min=num[k][l];
        return;
    }
    int m=(l+r)>>1;
    CBuild(rt,step<<1,l,m,k);
    CBuild(rt,step<<1|1,m+1,r,k);
    tree[rt].node[step].min=Min(tree[rt].node[step<<1].min,tree[rt].node[step<<1|1].min);
}

void SBuild(int rt,int step,int l,int r)
{
    tree[rt].node[step].l=l;
    tree[rt].node[step].r=r;
    if (l==r)
    {
        tree[rt].node[step].min=Min(tree[rt<<1].node[step].min,tree[rt<<1|1].node[step].min);
        return;
    }
    int m=(l+r)>>1;
    SBuild(rt,step<<1,l,m);
    SBuild(rt,step<<1|1,m+1,r);
    tree[rt].node[step].min=Min(tree[rt<<1].node[step].min,tree[rt<<1|1].node[step].min);
}

void Build(int step,int l,int r,int c1,int c2)
{
    tree[step].l=l;
    tree[step].r=r;
    if (l==r)
    {
        CBuild(step,1,c1,c2,l);
        return;
    }
    int m=(l+r)>>1;
    Build(step<<1,l,m,c1,c2);
    Build(step<<1|1,m+1,r,c1,c2);
    SBuild(step,1,c1,c2);
}

void SCompute(int rt,int step,int y1,int y2)
{
    if (tree[rt].node[step].l==y1 && tree[rt].node[step].r==y2)
    {
        if (minimum>tree[rt].node[step].min)
            minimum=tree[rt].node[step].min;
        return;
    }
    int m=(tree[rt].node[step].l+tree[rt].node[step].r)>>1;
    if (y2<=m)
    {
        SCompute(rt,step<<1,y1,y2);
    }
    else if (y1>m)
    {
        SCompute(rt,step<<1|1,y1,y2);
    }
    else
    {
        SCompute(rt,step<<1,y1,m);
        SCompute(rt,step<<1|1,m+1,y2);
    }
}

void Compute(int step,int x1,int x2,int y1,int y2)
{
    if (tree[step].l==x1&&tree[step].r==x2)
    {
        SCompute(step,1,y1,y2);
        return;
    }
    int m=(tree[step].l+tree[step].r)>>1;
    if (x2<=m)
    {
        Compute(step<<1,x1,x2,y1,y2);
    }
    else if (x1>m)
    {
        Compute(step<<1|1,x1,x2,y1,y2);
    }
    else
    {
        Compute(step<<1,x1,m,y1,y2);
        Compute(step<<1|1,m+1,x2,y1,y2);
    }
}

int main()
{
    int t,n,m;
    int i,j;
    int r1,r2,c1,c2;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        for (i=1;i<=n;i++)
            for (j=1;j<=n;j++)
                scanf("%d",&num[i][j]);
        Build(1,1,n,1,n);
        scanf("%d",&m);
        for (j=0;j<m;j++)
        {
            scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
            minimum=MAX;
            Compute(1,r1,r2,c1,c2);
            printf("%d\n",minimum);
        }
    }
    return 0;
}