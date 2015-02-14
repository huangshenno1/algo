#include <stdio.h>
#include <math.h>
int area2(int x1,int y1,int x2,int y2,int x3,int y3)
{
    int area;
    area=x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2;
    area=abs(area);
    return area;
}
int appro(int a,int b)
{
    int t;
    if (!a)
        return b;
    if (!b)
        return a;
    if (a==b)
        return a;
    if (a<b)
    {
        t=a;
        a=b;
        b=t;
    }
    t=a;
    while (t)
    {
        t=a%b;
        a=b;
        b=t;
    }
    return a;
}
void main()
{
    int x1,x2,x3,y1,y2,y3;
    int x,y,a,b;
    double s;
    scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
    while (x1||x2||x3||y1||y2||y3)
    {
        s=(double)area2(x1,y1,x2,y2,x3,y3)/2;
        b=appro(abs(x1-x2),abs(y1-y2))+appro(abs(x1-x3),abs(y1-y3))+appro(abs(x3-x2),abs(y3-y2));
        a=s+1-(double)b/2+0.5;
        printf("%d\n",a);
        scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
    }
}