#include <stdio.h>
#include <math.h>

int main()
{
    double x1,x2,x3,y1,y2,y3;
    while (scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3)==6)
    {
        double d1,d2,d3;
        d1=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
        d2=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
        d3=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
        printf("%.2lf\n",3.141592653589793*d1/sqrt(1-((d2*d2+d3*d3-d1*d1)/(2*d2*d3))*((d2*d2+d3*d3-d1*d1)/(2*d2*d3))));
    }
    return 0;
}