#include <stdio.h>

int main()
{
    char c;
    while (!feof(stdin))
    {
        scanf("%c",&c);
        if (c!=' ')
            printf("%c",c);
    }
    return 0;
}