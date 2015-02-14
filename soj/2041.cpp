#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    while (n)
    {
        if (n==1)
            printf("1\n");
        else printf("%d\n",2*n-2);
        scanf("%d",&n);
    }
    return 0;
}