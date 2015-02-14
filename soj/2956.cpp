#include <cstdio>
#include <cmath>

int main()
{
    int t;
    int n;
    int a;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        a=(double)(sqrt((double)n*2)+0.5);
        printf("%d\n",a);
    }
    return 0;
}