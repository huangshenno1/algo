#include <cstdio>
#include <cstring>

int main()
{
    int t,n,k,x,a[32],i;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%d",&n,&k);
        memset(a,0,sizeof(a));
        while (n--)
        {
            scanf("%d",&x);
            for (i=0;i<32;i++)
                a[i]+=(x&(1<<i))?1:0;
        }
        for (i=0;i<32;i++)
        {
            if (a[i]%(k+1)!=0)
                break;
        }
        if (i==32) puts("mm");
        else puts("T");
    }
    return 0;
}