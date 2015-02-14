#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        int ans;
        int temp;
        int count=1;
        scanf("%d",&ans);
        for (int i=1;i<n;i++)
        {
            scanf("%d",&temp);
            if (temp==ans)
            {
                count++;
            }
            else
            {
                count--;
                if (count==0)
                {
                    i++;
                    count=1;
                    scanf("%d",&ans);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}