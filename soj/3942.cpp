#include <stdio.h>
#include <math.h>

double integral(double b,double c,double x)
{
    return -x*x*x/3+b*x*x/2+c*x;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int iCase=0;iCase<t;iCase++)
    {
        double b,c;
        scanf("%lf%lf",&b,&c);
        if (b*b+4*c<=0)
        {
            printf("0.0\n");
        }
        else
        {
            double x1=(-b+sqrt(b*b+4*c))/-2;
            double x2=(-b-sqrt(b*b+4*c))/-2;
            printf("%.1lf\n",integral(b,c,x2)-integral(b,c,x1));
        }
    }
    return 0;
}