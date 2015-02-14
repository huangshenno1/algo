#include <cstdio>

int main()
{
    int n,a[60],i;
    while (scanf("%d",&n)==1)
    {
        for (i=0;i<n;i++)
            scanf("%d",&a[i]);
        for (i=0;i<n && a[i]==1;i++);
        if (i==n)
        {
            if (i&1) puts("Alice");
            else puts("Bob");
        }
        else
        {
            if (i&1) puts("Bob");
            else puts("Alice");
        }
    }
};