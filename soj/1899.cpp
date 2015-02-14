#include <stdio.h>

int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        if (n==0)
            break;
        int m=0,j=0,r;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&r);
            if (r)
                j++;
            else m++;
        }
        printf("Mary won %d times and John won %d times\n",m,j);
    }
    return 0;
}