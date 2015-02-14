#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    for (int iCase=0;iCase<n;iCase++)
    {
        int s,d;
        scanf("%d%d",&s,&d);
        if (s<d||(s-d)%2)
            printf("impossible\n");
        else
            printf("%d %d\n",(s+d)/2,(s-d)/2);
    }
    return 0;
}