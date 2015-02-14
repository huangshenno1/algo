#include <cstdio>

int main()
{
    int n, m, k, ans;
    while (scanf("%d%d",&n,&k)==2)
    {
        for (m=1;k;k--) m*=10;
        int r=n%m;
        if (r==0||r<m/2) n-=r;
        else n=n-r+m;
        printf("%d\n",n);
    }
    return 0;
}