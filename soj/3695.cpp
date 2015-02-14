#include <stdio.h>
#include <math.h>

int x[1000001]={1};

int main()
{
    for (int i=1;i<=1000000;i++)
    {
        x[i]=(x[(int)(i-sqrt((double)i))]+x[(int)log((double)i)]+x[(int)(i*sin((double)i)*sin((double)i))])%1000000;
    }
    int n;
    scanf("%d",&n);
    while (n!=-1)
    {
        printf("%d\n",x[n]);
        scanf("%d",&n);
    }
    return 0;
}