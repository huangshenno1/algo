#include <stdio.h>
#include <string.h>

int p[300];

int Parent(int n)
{
    if (p[n]==-1)
        return n;
    return p[n]=Parent(p[n]);
}

void Swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}

int main()
{
    int n,m;
    int a,b;
    int i,count;
    while (scanf("%d%d",&n,&m)==2)
    {
        memset(p,-1,sizeof(p));
        while (m--)
        {
            scanf("%d%d",&a,&b);
            a=Parent(a);
            b=Parent(b);
            if (a==b)
                continue;
            if (b==1)
                Swap(a,b);
            p[b]=a;
        }
        count=0;
        for (i=1;i<=n;i++)
        {
            if (Parent(i)!=1)
            {
                printf("%d\n",i);
                count++;
            }
        }
        if (!count)
            printf("0\n");
    }
    return 0;
}