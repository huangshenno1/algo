#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d",&n);
    for (int iCase=0;iCase<n;iCase++)
    {
        double x,y;
        scanf("%lf",&x);
        y=x;
        for (int i=0;i<100;i++)
        {
            y=y+(x/(y*y)-y)*1.0/3.0;
        }
        printf("%.6lf\n",y);
    }
    return 0;
}