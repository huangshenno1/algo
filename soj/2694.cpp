#include <stdio.h>
#include <math.h>

int main()
{
    int t;
    scanf("%d",&t);
    for (int iCase=0;iCase<t;iCase++)
    {
        int n,m;
        scanf("%d",&n);
        m=ceil(log((double)n)/log(2.0));
        printf("%d\n",m);
    }
    return 0;
}