#include <stdio.h>
#include <math.h>

int main()
{
    double x1,y1,r1,x2,y2,r2;
    while (scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&r1,&x2,&y2,&r2)==6)
    {
        double d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        double theta1=2*acos((d*d+r1*r1-r2*r2)/(2*d*r1));
        double theta2=2*acos((d*d+r2*r2-r1*r1)/(2*d*r2));
        double s=r1*r1*theta1/2+r2*r2*theta2/2-d*r1*sin(theta1/2);
        printf("%.3lf\n",s);
    }
    return 0;
}