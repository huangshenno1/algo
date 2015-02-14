#include <stdio.h>

int main()
{
    char n[12];
    while (scanf("%s",n)==1)
    {
        if (n[0]=='-')
            printf("%s\n",n+1);
        else if (n[0]=='0')
            printf("0\n");
        else printf("-%s\n",n);
    }
    return 0;
}