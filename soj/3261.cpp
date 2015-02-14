#include <stdio.h>

int main()
{
    int t,iCase=1;
    int w,b;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%d",&w,&b);
        printf("Case #%d: ",iCase++);
        if (b&1)
            printf("BLACK\n");
        else
            printf("WHITE\n");
    }
    return 0;
}