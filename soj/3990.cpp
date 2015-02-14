#include <stdio.h>

int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        int max=0;
        int start,end;
        scanf("%d",&start);
        end=start;
        int temp;
        for (int i=1;i<n;i++)
        {
            scanf("%d",&temp);
            if (temp<=end)
            {
                if (end-start>max)
                    max=end-start;
                start=end=temp;
            }
            else
            {
                end=temp;
                if (i==n-1)
                {
                    if (end-start>max)
                        max=end-start;
                }
            }
        }
        printf("%d\n",max);
    }
    return 0;
}