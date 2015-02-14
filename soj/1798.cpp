#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    for (int iCase=1;iCase<=t;iCase++)
    {
        int sequence[1000];
        int inverse=0;
        int n;
        scanf("%d",&n);
        for (int i=0;i<n;i++)
        {
            scanf("%d",&sequence[i]);
            for (int j=0;j<i;j++)
            {
                if (sequence[j]>sequence[i])
                    inverse++;
            }
        }
        printf("Scenario #%d:\n",iCase);
        printf("%d\n\n",inverse);
    }
    return 0;
}