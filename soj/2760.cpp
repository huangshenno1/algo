#include <stdio.h>

int main()
{
    long long a,b;
    while (scanf("%lld%lld",&a,&b)==2)
    {
        printf("%lld\n",((a+1)*a/2)*((b+1)*b/2));
    }
    return 0;
}