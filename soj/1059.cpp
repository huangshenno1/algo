#include <stdio.h>
#include <math.h>
#define N 60
int factor(int a,int b);
void main()
{
    int a[N];
    int n,i,j,count,comb;
    scanf("%d",&n);
    while (n!=0)
    {
        count=0;
        comb=n*(n-1)/2;
        for (i=0;i<n;i++)
            scanf("%d",&a[i]);
        for (i=0;i<n-1;i++)
            for (j=i+1;j<n;j++)
                if (factor(a[i],a[j])==1)
                    count++;
        if (count)
            printf("%lf\n",sqrt(6*(double)comb/count));
        else printf("No estimate for this data set.\n");
        scanf("%d",&n);
    }
}
int factor(int a,int b)
{
    int r,t;
    if (a<b)
    {
        t=a;
        a=b;
        b=t;
    }
    r=1;
    while (r!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}