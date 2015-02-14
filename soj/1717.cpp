#include <stdio.h>
#include <math.h>

int main()
{
    long long x,b,p;
    while (scanf("%lld",&x)==1)
    {
        if (!x)
            break;
        bool flag_minus=0;
        if (x<0)
        {
            flag_minus=1;
            x=-x;
        }
        for (p=32;p>1;p--)
        {
            if ((long long)(pow((double)((long long)(pow((double)x,1.0/p)+0.5)),(double)p)+0.5)==x)
            {
                if (flag_minus&&(p+1)%2)
                    continue;
                printf("%lld\n",p);
                break;
            }
        }
        if (p==1)
            printf("1\n");
    }
    return 0;
}