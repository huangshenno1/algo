#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    for (int iCase=0;iCase<t;iCase++)
    {
        long long a,b;
        scanf("%lld%lld",&a,&b);
        printf("%lld\n",a^b);
    }
    return 0;
}