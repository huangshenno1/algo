#include <stdio.h>

long long CommonDivisorSquare(long long a,long long b)
{
    if (a<b)
    {
        double t=a;
        a=b;
        b=t;
    }
    int q=a/b;
    int r=a-q*b;
    while (r)
    {
        a=b;
        b=r;
        q=a/b;
        r=a-q*b;
    }
    return b*b;
}

int main()
{
    double w,h;
    scanf("%lf%lf",&w,&h);
    while (w&&h)
    {
        long long ww=w*100+.05;
        long long hh=h*100+0.5;
        int ans=ww*hh/CommonDivisorSquare(ww,hh);
        printf("%d\n",ans);
        scanf("%lf%lf",&w,&h);
    }
    return 0;
}