#include <stdio.h>

int main()
{
    double a,b,c,d,e;
    scanf("%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e);
    while (a||b||c||d||e)
    {
        double s=a+b+c+d+e;
        if (s<0&&s>-0.001)
            s=0;
        printf("%.3lf\n",s);
        scanf("%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e);
    }
    return 0;
}