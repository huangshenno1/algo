#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        unsigned int n;
        scanf("%u",&n);
        int r=n%11;
        if (r>=1&&r<=9)
            printf("Win\n");
        else
            printf("Fail\n");
    }
    return 0;
}