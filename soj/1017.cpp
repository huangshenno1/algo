#include <stdio.h>
#include <math.h>
void main()
{
    double p;
    int n,k;
    while (scanf("%d%lf",&n,&p)==2)
    {
        k=pow(p,1.0/n)+0.5;
        printf("%d\n",k);
    }
}