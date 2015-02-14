#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    for (int iCase=0;iCase<n;iCase++)
    {
        int k;
        scanf("%d",&k);
        int ans=(k-1)*4.0/5.0+0.8+1;
        printf("%d\n",ans);
    }
    return 0;
}