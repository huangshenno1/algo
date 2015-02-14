#include <stdio.h>

int main()
{
    char str[110];
    int count=0;
    while (gets(str))
    {
        count++;
    }
    printf("%d\n",count);
    return 0;
}