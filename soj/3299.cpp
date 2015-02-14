#include <stdio.h>

int n,m;
int a[21];
bool flag;

void f(int s,int k)
{
    if (flag)
        return;
    if (k==n)
    {
        if (s==m)
            flag=1;
        return;
    }
    f(s+a[k],k+1);
    if (flag)
        return;
    f(s-a[k],k+1);
}

int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        flag=0;
        scanf("%d%d",&n,&m);
        for (int i=0;i<n;i++)
            scanf("%d",&a[i]);
        f(a[0]-a[1],2);
        if (flag)
            printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}