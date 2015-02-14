#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    while (n)
    {
        printf("%d\n",(n+1)/2);
        scanf("%d",&n);
    }
    return 0;
}