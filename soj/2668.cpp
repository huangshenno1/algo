#include <cstdio>

int f(int x)
{
    int res=0;
    while (x)
    {
        x>>=1;
        res+=x;
    }
    return res;
}

int main()
{
    int n,k;
    while (scanf("%d%d",&n,&k)==2 && n)
    {
        int cnt=f(n)-f(n-k)-f(k);
        if (cnt>0) puts("0");
        else puts("1");
    }
    return 0;
}
