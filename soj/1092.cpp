#include <cstdio>
typedef long long LL;

void gcd(LL a,LL b,LL &d,LL &x,LL &y)
{
    if (!b) {d=a;x=1;y=0;}
    else {gcd(b,a%b,d,y,x);y-=x*(a/b);}
}

int main()
{
    LL a,b,d,x,y;
    while (scanf("%lld%lld",&a,&b)==2 && a)
    {
        gcd(a,b,d,x,y);
        while (x<0)
            x+=b;
        while (x-b>=0)
            x-=b;
        printf("%lld\n",x);
    }
    return 0;
}