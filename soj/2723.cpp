#include <cstdio>

const int maxn = 50002;
int n,h[maxn],i;

int main()
{
    while (scanf("%d",&n)==1)
    {
        for (i=1;i<=n;i++) scanf("%d",&h[i]);
        i=1;
        while (i<=n)
        {
            h[i-1]=0;
            while (i<=n && h[i]>h[i-1]) i++;
            printf("%d\n",i-1);
            while (i<=n && h[i]<h[i-1]) i++;
        }
    }
    return 0;
}