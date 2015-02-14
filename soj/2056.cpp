#include <stdio.h>
#include <math.h>

int main()
{
    int k;
    scanf("%d",&k);
    while (k)
    {
        int q=sqrt((double)k);
        printf("%d\n",q);
        scanf("%d",&k);
    }
    return 0;
}