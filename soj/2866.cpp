#include <stdio.h>

int main()
{
    unsigned long long m,n;
    while (scanf("%llu%llu",&m,&n)==2)
    {
        unsigned long long score=0;
        if (m<n)
        {
            unsigned long long t=m;
            m=n;
            n=t;
        }
        unsigned long long r=1;
        unsigned long long q;
        while (r!=0)
        {
            r=m%n;
            q=m/n;
            score+=q*n*n*n*n;
            m=n;
            n=r;
            if (m<n)
            {
                unsigned long long t=m;
                m=n;
                n=t;
            }
        }
        printf("%llu\n",score);
    }
    return 0;
}