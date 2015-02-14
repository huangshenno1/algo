#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    while (n)
    {
        int s;
        if (n>999)
        {
            s=9+90*2+900*3+(n-999)*4;
        }
        else if (n>99)
        {
            s=9+90*2+(n-99)*3;
        }
        else if (n>9)
        {
            s=9+(n-9)*2;
        }
        else
        {
            s=n;
        }
        printf("%d\n",s);
        scanf("%d",&n);
    }
}