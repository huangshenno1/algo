#include <stdio.h>

int main()
{
    int sum=0, n;
    while (scanf("%d",&n)==1)
    {
        sum+=n;
    }
    printf("%d",sum);
    return 0;
}