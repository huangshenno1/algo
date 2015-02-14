#include <stdio.h>
#include <math.h>

typedef struct 
{
    double x,y;
}Coordinate;

typedef struct
{
    double a,b,c;
}Line;

double Distance(Coordinate p, Coordinate q)
{
    return sqrt((p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y));
}

Coordinate Reflect(Coordinate p, Line l)
{
    Coordinate _p;
    _p.x=((l.b*l.b-l.a*l.a)*p.x-2*l.a*l.b*p.y-2*l.a*l.c)/(l.a*l.a+l.b*l.b);
    _p.y=((l.a*l.a-l.b*l.b)*p.y-2*l.a*l.b*p.x-2*l.b*l.c)/(l.a*l.a+l.b*l.b);
    return _p;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int iCase=0;iCase<t;iCase++)
    {
        Coordinate p,q;
        Line l;
        double d;
        scanf("%lf%lf%lf%lf%lf%lf%lf",&p.x,&p.y,&q.x,&q.y,&l.a,&l.b,&l.c);
        if ((l.a*p.x+l.b*p.y+l.c)*(l.a*q.x+l.b*q.y+l.c)>=0)
            p=Reflect(p,l);
        d=Distance(p,q);
        printf("%.1lf\n",d);
    }
    return 0;
}