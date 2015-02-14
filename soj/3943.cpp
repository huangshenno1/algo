#include <cstdio>
#include <cmath>

const double PI = acos(-1.0);

int T;
double w,h,r,ans;

void swap(double &a, double &b)
{
    double temp = a;
    a = b;
    b = temp;
}

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%lf%lf%lf",&w,&h,&r);
        if (w < h) swap(w,h);

        if (r <= h)
        {
            ans = r * r * PI * 0.75;
            printf("%.3lf\n",ans);
        }
        else if (r <= w)
        {
            ans = r * r * PI * 0.75 + (r-h) * (r-h) * PI * 0.25;
            printf("%.3lf\n",ans);
        }
        else if (r <= w + h)
        {
            ans = r * r * PI * 0.75 + (r-h) * (r-h) * PI * 0.25 + (r-w) * (r-w) * PI * 0.25;
            printf("%.3lf\n",ans);
        }
        else
        {
            double a,b,c,a1,a2;
            a = r - w;
            b = r - h;
            c = sqrt(w * w + h * h);   
            a1 = acos((a*a + c*c - b*b)/(2*a*c)) - acos(h/c);
            a2 = acos((b*b + c*c - a*a)/(2*b*c)) - acos(w/c);     
            ans = r * r * PI * 0.75 + a * a * (PI/2 - a1) / 2 + b * b * (PI/2 - a2) / 2 + a * h * sin(a1) / 2 + b * w * sin(a2) / 2;
            printf("%.3lf\n",ans);
        }
    }
    return 0;
}