#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    for (int iCase=0;iCase<t;iCase++)
    {
        double p;
        int r;
        scanf("%lf%d",&p,&r);
        if (p==0||r/p>=1000000)
            printf("-1\n");
        else printf("%.2lf\n",r/p);
    }
    return 0;
}