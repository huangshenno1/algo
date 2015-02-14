#include <cstdio>

int main()
{
    long long n;
    long long r;
    bool f1,f2,f3;
    while (scanf("%lld",&n)==1)
    {
        r=1;
        f1=0;
        while (r<n)
        {
            if (9*r>=n)
            {
                f1=1;
                break;
            }
            r*=18;
        }
        r=2;
        f2=1;
        while (r<n)
        {
            if (9*r>=n)
            {
                f2=0;
                break;
            }
            r*=18;
        }
        r=9;
        f3=1;
        while (r<n)
        {
            if (9*r>=n)
            {
                f3=0;
                break;
            }
            r*=18;
        }

        if (f1||f2||f3)
            printf("Stan wins.\n");
        else
            printf("Ollie wins.\n");
    }
    return 0;
}