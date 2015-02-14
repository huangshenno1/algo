#include <stdio.h>

int main()
{
    int n;
    int d[20],p[20];
    int iCase=1;
    int i;
    double min;
    int min_i;
    while (scanf("%d",&n)==1)
    {
        for (i=0;i<n;i++)
            scanf("%d%d",&d[i],&p[i]);
        min=(double)p[0]/(d[0]*d[0]);
        min_i=0;
        for (i=1;i<n;i++)
        {
            if ((double)p[i]/(d[i]*d[i])<min)
            {
                min=(double)p[i]/(d[i]*d[i]);
                min_i=i;
            }
        }
        printf("Menu %d: ",iCase++);
        printf("%d\n",d[min_i]);
    }
    return 0;
}