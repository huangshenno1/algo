#include <stdio.h>
#include <math.h>

double Min(double a,double b)
{
    return a<b?a:b;
}

double Max(double a,double b)
{
    return a>b?a:b;
}

double Dis(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

void Line(double x1,double y1,double x2,double y2,double &a,double &b,double &c)
{
    a=y2-y1;
    b=x1-x2;
    c=y1*x2-y2*x1;
}

void CrossPoint(double a1,double b1,double c1,double a2,double b2,double c2,double &x,double &y)
{
    x=(c1*b2-c2*b1)/(a2*b1-a1*b2);
    y=(c1*a2-c2*a1)/(b2*a1-b1*a2);
}

bool InLine(double x,double y,double x1,double y1,double x2,double y2)
{
    if (x>=Min(x1,x2)&&x<=Max(x1,x2) && y>=Min(y1,y2)&&y<=Max(y1,y2))
        return 1;
    return 0;
}

int main()
{
    double x1,x2,y1,y2;
    double sx,sy,ex,ey;
    double a1,a2,b1,b2,c1,c2;
    double x,y;
    int iCase=1;
    while (scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2)==4 && x1 && x2 && y1 && y2)
    {
        scanf("%lf%lf%lf%lf",&sx,&sy,&ex,&ey);
        Line(x1,y1,x2,y2,a1,b1,c1);
        Line(sx,sy,ex,ey,a2,b2,c2);
        CrossPoint(a1,b1,c1,a2,b2,c2,x,y);
        if (InLine(x,y,x1,y1,x2,y2)&&InLine(x,y,sx,sy,ex,ey))
        {
            printf("Case %d: %.3lf\n",iCase++,Min(Dis(x1,y1,ex,ey)+Dis(x2,y2,ex,ey),Dis(x1,y1,sx,sy)+Dis(x2,y2,sx,sy))/2);
        }
        else
        {
            printf("Case %d: %.3lf\n",iCase++,Dis(x1,y1,x2,y2)/2);
        }
    }
    return 0;
}