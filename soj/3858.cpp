#include <stdio.h>

int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        if (n/1000000000)
        {
            printf("%d,%03d,%03d,%03d\n",n/1000000000,(n%1000000000)/1000000,(n%1000000)/1000,n%1000);
        }
        else if (n/1000000)
        {
            printf("%d,%03d,%03d\n",n/1000000,(n%1000000)/1000,n%1000);
        }
        else if (n/1000)
        {
            printf("%d,%03d\n",n/1000,n%1000);
        }
        else
        {
            printf("%d\n",n);
        }
    }
    return 0;
}