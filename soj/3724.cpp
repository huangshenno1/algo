#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    for (int iCase=1;iCase<=t;iCase++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        printf("Scenario #%d:\n",iCase);
        if (a*a+b*b==c*c||a*a+c*c==b*b||b*b+c*c==a*a)
            printf("yes\n\n");
        else printf("no\n\n");
    }
    return 0;
}