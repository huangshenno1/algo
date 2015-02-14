#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    for (int iCase=0;iCase<t;iCase++)
    {
        int n;
        scanf("%d",&n);
        if (n<=10)
            printf("1.00\n");
        else printf("%.2lf\n",0.15*n-0.5);
    }
    return 0;
}