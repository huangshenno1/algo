#include <stdio.h>
#include <math.h>

int main()
{
    double SQRT_5=sqrt(5.0);
    int t,k,l;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&k);
        l=k*(log10(1+SQRT_5)-log10(2.0))-log10(SQRT_5)+1;
        printf("%d\n",l);
    }
    return 0;
}