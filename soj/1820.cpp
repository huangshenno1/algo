#include <stdio.h>
#include <math.h>

int main()
{
    double R,r;
    int n;
    int iCaseAmount;
    scanf("%d",&iCaseAmount);
    for (int iCase=1;iCase<=iCaseAmount;iCase++)
    {
        scanf("%lf%d",&R,&n);
        double alpha=2*3.14159265354/n;
        r=R*sin(alpha)/(2*cos(alpha/2)+sin(alpha));
        printf("Scenario #%d:\n",iCase);
        printf("%.3lf\n\n",r);
    }
    return 0;
}
