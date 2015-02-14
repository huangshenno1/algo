#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    for (int iCase=0;iCase<t;iCase++)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if ((m*n)%2)
            printf("Aoiing will win.\n");
        else printf("Zhym will win.\n");
    }
    return 0;
}