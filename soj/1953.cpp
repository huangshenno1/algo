#include <stdio.h>
#include <string.h>

int a[100010]={0};
int p[100010];
int w=0;

void Insert(int l,int k)
{
    if (l>w)
    {
        w=l;
        a[l]=k;
        if (a[l-1])
            p[l-1]=l;
    }
    else
    {
        if (a[l]!=0)
        {
            int r=l;
            while (l!=p[l])
                l=p[l];
            p[r]=l;
            p[l]=l+1;
            a[++l]=k;
            if (a[l+1])
                p[l]=l+1;
        }
        else
        {
            a[l]=k;
            if (a[l-1])
                p[l-1]=l;
            if (a[l+1])
                p[l]=l+1;
        }
        if (l>w)
            w=l;
    }
}

int main()
{
    for (int i=1;i<=100000;i++)
        p[i]=i;
    int n;
    scanf("%d",&n);
    while (n)
    {
        int l;
        for (int k=1;k<=n;k++)
        {
            scanf("%d",&l);
            Insert(l,k);
        }

        printf("%d\n%d",w,a[1]);
        for (int i=2;i<=w;i++)
            printf(" %d",a[i]);
        printf("\n");

        memset(a,0,sizeof(a));
        for (int i=1;i<=100000;i++)
            p[i]=i;
        w=0;
        scanf("%d",&n);
    }

    return 0;
}