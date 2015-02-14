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
        int temp;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&temp);
            s+=temp;
        }
        if ((s-n)%2)
            printf("dz win!\n");
        else
            printf("gz win!\n");
    }
    return 0;
}