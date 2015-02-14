#include <stdio.h>

int main()
{
    int t,n;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        if (n<32)
            printf("%u\n",(1<<n)-1);
        else printf("4294967295\n");
    }
    return 0;
}