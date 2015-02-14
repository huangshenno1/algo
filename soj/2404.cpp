#include <cstdio>

int main()
{
    long long h[21]={1};
    for (int i=1;i<=20;i++)
        h[i]=h[i-1]*(4*i-2)/(i+1);
    int n;
    while (scanf("%d",&n)==1)
        printf("%lld\n",h[n]);
    return 0;
}