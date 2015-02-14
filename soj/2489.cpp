#include <stdio.h>

int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    while (m||n)
    {
        int s=3*m-n;
        printf("%d\n",s);
        scanf("%d%d",&m,&n);
    }
    return 0;
}