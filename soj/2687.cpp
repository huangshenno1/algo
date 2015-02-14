#include <stdio.h>

int main()
{
    int n,a,b;
    while (scanf("%d%d%d",&n,&a,&b)==3)
    {
        int r=n%(a+b);
        if (r>=a&&r<=b)
            printf("windy7926778\n");
        else printf("fgjlwj\n");
    }
    return 0;
}