#include <cstdio>

int gcd(int a,int b)
{
    return b==0 ? a:gcd(b,a%b);
}

int main()
{
    int T,t,a,b,g,l;
    scanf("%d",&T);
    for (t=1;t<=T;t++)
    {
        scanf("%d%d",&a,&b);
        g=gcd(a,b);
        l=a*b/g;
        printf("%d %d %d\n",t,l,g);
    }
    return 0;
}