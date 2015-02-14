#include <stdio.h>

int main()
{
    unsigned int n;
    int t;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%u",&n);
        printf("%u\n",2*n-2);
    }
    return 0;
}