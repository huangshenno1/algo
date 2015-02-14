#include <stdio.h>
#include <math.h>

#define PI 3.14159265354

double distance(double x1,double y1,double z1,double x2,double y2,double z2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
}

int main()
{
    double x1,y1,z1,x2,y2,z2,x3,y3,z3;
    while (scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&z1,&x2,&y2,&z2,&x3,&y3,&z3)==9)
    {
        double a=distance(x2,y2,z2,x3,y3,z3);
        double b=distance(x1,y1,z1,x3,y3,z3);
        double c=distance(x2,y2,z2,x1,y1,z1);
        double p=(a+b+c)/2;
        double s1=PI*(p-a)*(p-b)*(p-c)/p;
        double cosA=(b*b+c*c-a*a)/(2*b*c);
        double sinA=sqrt(1-cosA*cosA);
        double s2=PI*(a/sinA/2)*(a/sinA/2);
        double ratio=s1/s2;
        printf("%.3lf\n",ratio);
    }
    return 0;
}