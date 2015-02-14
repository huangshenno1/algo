#include <stdio.h>

int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        int point[100];
        for (int i=0;i<n;i++)
        {
            scanf("%d",&point[i]);
        }
        int totalpoints=0;
        for (int i=n-2;i>=0;i--)
        {
            if (point[i]>=point[i+1])
            {
                totalpoints+=point[i]-point[i+1]+1;
                point[i]=point[i+1]-1;
            }
        }
        printf("%d\n",totalpoints);
    }
    return 0;
}