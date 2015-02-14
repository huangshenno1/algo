#include <stdio.h>

int main()
{
    double initial,rate,final;
    while (scanf("%lf%lf%lf",&initial,&rate,&final)==3)
    {
        int count=0;
        rate=1+rate/100;
        while (initial<final)
        {
            initial*=rate;
            count++;
        }
        printf("%d\n",count);
    }
    return 0;
}