#include <stdio.h>

long long ceiling(double n)
{
    if (n-(long long)n<0.001)
        return (long long)n;
    else return (long long)n+1;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int iCase=0;iCase<t;iCase++)
    {
        long long n;
        scanf("%lld",&n);
        printf("%lld\n",ceiling((n-1)*4.0/5)+1);
    }
    return 0;
}