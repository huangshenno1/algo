#include <stdio.h>

int main()
{
    unsigned long long n;
    while (scanf("%llu",&n)==1)
    {
        printf("%llu\n",2*n*n-n+1);
    }
    return 0;
}