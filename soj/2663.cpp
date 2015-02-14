#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    for (int iCase=0;iCase<t;iCase++)
    {
        int n;
        scanf("%d",&n);
        printf("%d %d\n",n*n-n+1,n*n+n-1);
    }
    return 0;
}