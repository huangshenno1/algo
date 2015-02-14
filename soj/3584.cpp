#include <cstdio>

bool f(long long a , long long b , long long c)
{
    if (a<= c && c<a+a+b) return 1;
    return 0;
}

int main()
{
    int T;
    long long a,b,c;
    scanf("%d",&T); 
    while (T--)
    {
        scanf("%lld%lld%lld",&a,&b,&c);
        c %= (a+a+b+b);
        puts(f(a,b,c) ? "no":"yes" );    
    }
    return 0;    
}