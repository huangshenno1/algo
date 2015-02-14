#include <stdio.h>
#include <math.h>

int main()
{
    int t;
    scanf("%d",&t);
    for (int iCase=0;iCase<t;iCase++)
    {
        double x[3],y[3];
        for (int i=0;i<3;i++)
        {
            scanf("%lf%lf",&x[i],&y[i]);    
        }
        double s=(x[2]-x[0])*(y[1]-y[0])-(x[1]-x[0])*(y[2]-y[0]);
        if (!s)
            printf("Error\n");
        else
        {            
            if (s<0)
                s=-s;
            printf("%.1lf\n",s);
        }
    }
}