#include <cstdio>

#define PI 3.141592653589793

int main()
{
    int iCase;
    int n,f;
    int t;
    double s[10010];
    double high,low,mid;
    int i;
    scanf("%d",&iCase);
    while (iCase--)
    {
        high=low=0;
        scanf("%d%d",&n,&f);
        for (i=0;i<n;i++)
        {
            scanf("%lf",&s[i]);
            s[i]=s[i]*s[i]*PI;
            if (s[i]>high)
                high=s[i];
        }
        
        while (high-low>=0.0000001 || low-high>=0.0000001)
        {
            mid=(high+low)/2;
            t=f+1;
            for (i=0;i<n;i++)
                t-=(int)(s[i]/mid);
            if (t<=0)
                low=mid;
            else high=mid;
        }

        printf("%.6lf\n",mid);
    }
    return 0;
}