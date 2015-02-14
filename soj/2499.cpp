#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    for (int iCase=0;iCase<t;iCase++)
    {
        int n;
        scanf("%d",&n);
        int s=0;
        for (int i=0;i<n;i++)
        {
            int a;
            scanf("%d",&a);
            s+=a;
        }
        if (!(s%n))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}