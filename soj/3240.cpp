#include <stdio.h>

int main()
{
    int t,iCase;
    double s;
    char unit[3];
    scanf("%d",&t);
    for (iCase=1;iCase<=t;iCase++)
    {
        printf("%d ",iCase);
        scanf("%lf %s",&s,unit);
        if (unit[0]=='k')
        {
            s*=2.2046;
            printf("%.4lf lb\n",s);
        }
        else if (unit[0]=='l'&&unit[1]=='b')
        {
            s*=0.4536;
            printf("%.4lf kg\n",s);
        }
        else if (unit[0]=='l')
        {
            s*=0.2642;
            printf("%.4lf g\n",s);
        }
        else
        {
            s*=3.7854;
            printf("%.4lf l\n",s);
        }
    }
    return 0;
}