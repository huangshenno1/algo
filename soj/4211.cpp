#include <stdio.h>

double Abs(double a)
{
    return a>0?a:-a;
}

double f(double a,double b,double c,double d,double v)
{
    return a*v*v*v+b*v*v+c*v+d;
}

double Solve(double a,double b,double c,double d,double y)
{
    double low=0,high=1000;
    double mid=(low+high)/2;
    double temp=f(a,b,c,d,mid);
    while (Abs(temp-y)>=0.000001)
    {
        if (temp>y)
        {
            high=mid;
            mid=(low+high)/2;
        }
        else
        {
            low=mid;
            mid=(low+high)/2;
        }
        temp=f(a,b,c,d,mid);
    }
    mid=(int)(mid*100)/100.0;
    return mid;
}

int main()
{
//    freopen("in.txt","r",stdin);
    double a,b,c,d,m,t;
    double ans;
    while (scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&m,&t)==6 && t)
    {
        ans=Solve(a,b,c,d,t/m);
        printf("%.2lf\n",ans);
    }
    return 0;
}