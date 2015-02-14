#include <stdio.h>

int main()
{
    int m,n,k;
    while (scanf("%d%d%d",&m,&n,&k)==3)
    {
        int rest=m+n-k;
        int best_n=rest/3;
        int best_m=best_n*2;
        if (m<best_m)
            printf("%d\n",m/2);
        else if (n<best_n)
            printf("%d\n",n);
        else
            printf("%d\n",best_n);
    }
    return 0;
}