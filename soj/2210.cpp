#include <stdio.h>
#include <math.h>

double min(double a,double b)
{
    return a<b?a:b;
}

double abs(double a)
{
    return a>=0?a:-a;
}

double cal(double d,double x,double y,double c)
{
    return sqrt(c*c/(x*x-d*d))+sqrt(c*c/(y*y-d*d));
}

int main()
{
    double x,y,c;
    while (scanf("%lf%lf%lf",&x,&y,&c)==3)
    {
        double low=0,high=min(x,y);
        double d=(high+low)/2;
        double call=cal(d,x,y,c)-1;
        while (abs(call)>0.000001)
        {
            if (call>0)
            {
                high=d;
            }
            else
            {
                low=d;
            }
            d=(high+low)/2;
            call=cal(d,x,y,c)-1;
        }
        printf("%.3lf\n",d);
    }
    return 0;
}