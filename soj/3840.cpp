#include <stdio.h>

int main()
{
    double a,b,c,i,j,k;
    while (scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&i,&j,&k)==6)
    {
        if ((a/i)<=(b/j)&&(a/i)<=(c/k))
            printf("%lf %lf %lf\n",0.0,b-a*j/i,c-a*k/i);
        else if((b/j)<=(a/i)&&(b/j)<=(c/k))
            printf("%lf %lf %lf\n",a-b*i/j,0.0,c-b*k/j);
        else
            printf("%lf %lf %lf\n",a-c*i/k,b-c*j/k,0.0);
    }
    return 0;
}