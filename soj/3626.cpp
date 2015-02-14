#include <stdio.h>

int main()
{
    int t;
    int iCase;
    int x,y;
    scanf("%d",&t);
    for (iCase=0;iCase<t;iCase++)
    {
        scanf("%d%d",&x,&y);
        printf("%.4lf\n",(double)x/(x+2*y));
    }
    return 0;
}