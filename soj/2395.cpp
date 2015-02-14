#include <cstdio>

int g[]={0,1,2,3,0,4,5,6,7,8};

int f(int n)
{
    int res=0,r=1;
    while (n)
    {
        res+=g[n%10]*r;
        n/=10;
        r*=9;
    }
    return res;
}

int main()
{
    int n;
    while (scanf("%d",&n)==1 && n)
        printf("%d: %d\n",n,f(n));
    return 0;
}