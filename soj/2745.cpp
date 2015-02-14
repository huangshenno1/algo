#include <stdio.h>
#include <string.h>

int a[100010];
int c[100010];

int LowBit(int n)
{
    return n & (n^(n-1));
}

void Change(int p,int add,int n)
{
    while (p<=n)
    {
        c[p]+=add;
        p+=LowBit(p);
    }
}

int Sum(int p)
{
    int s=0;
    while (p>0)
    {
        s+=c[p];
        p-=LowBit(p);
    }
    return s;
}

int main()
{
    int n,m;
    int b,p,q;
    int i;
    while (scanf("%d%d",&n,&m)==2)
    {
        memset(a,0,sizeof(a));
        memset(c,0,sizeof(c));
        for (i=0;i<m;i++)
        {
            scanf("%d%d%d",&b,&p,&q);
            if (b==1)
            {
                Change(p+1,q,n);
            }
            else
            {
                printf("%d\n",Sum(q+1)-Sum(p));
            }
        }
    }
    return 0;
}