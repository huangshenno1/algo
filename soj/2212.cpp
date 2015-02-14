#include <stdio.h>

int main()
{
    int n,k;
    while (scanf("%d%d",&n,&k)==2)
    {
        int ans=n+n/(k-1);
        if (n%(k-1)==0)
            ans--;
        printf("%d\n",ans);
    }
    return 0;
}