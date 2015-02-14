#include <stdio.h>

int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        int x[1010];
        for (int i=0;i<n;i++)
            scanf("%d",&x[i]);
        for (int i=0;i<n;i++)
        {
            int power=0;
            for (int j=i+1;j<n;j++)
            {
                if (x[j]>x[i])
                {
                    power=x[j];
                    break;
                }
            }
            printf("%d\n",power);
        }
    }
    return 0;
}