#include <stdio.h>

double Pow(double x,int y)
{
    double ans=1;
    while (y)
    {
        if (y&1)
            ans*=x;
        x*=x;
        y>>=1;
    }
    return ans;
}

int main()
{
//    freopen("in.txt","r",stdin);
    double x,y,r;
    int n;
    double s;
    int i;
    while (scanf("%lf%lf%d%lf",&x,&y,&n,&r)==4 && (x||y||n||r))
    {
        if (y<=x*r/1200)
        {
            printf("NO\n");
            continue;
        }
        if (r==0)
        {
            if (x<=y*12*n)
                printf("YES\n");
            else printf("NO\n");
            continue;
        }
        s=(x-1200*y/r)*Pow(1+r/1200,12*n)+1200*y/r;
        if (s<0.1)
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}