#include <stdio.h>

int n;
int count;
int init[11];

void f(int i,int k)
{
    if (init[i]!=0 && init[i]!=k)
        return;
    if (i==n)
    {
        count++;
        return;
    }
    if (k==1)
    {
        f(i+1,k);
        f(i+1,k+1);
    }
    else if (k==n)
    {
        f(i+1,k-1);
        f(i+1,k);
    }
    else
    {
        f(i+1,k-1);
        f(i+1,k);
        f(i+1,k+1);
    }
}

int main()
{
    while (scanf("%d",&n)==1 && n)
    {
        count=0;
        for (int i=1;i<=n;i++)
            scanf("%d",&init[i]);
        for (int k=1;k<=n;k++)
            f(1,k);
        printf("%d\n",count);
    }
    return 0;
}