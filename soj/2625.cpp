#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    while (n)
    {
        int width=1;
        int length=0;
        while (n)
        {
            int digit=n%10;
            if (digit==1)
                width+=2;
            else if (digit==0)
                width+=4;
            else width+=3;
            n/=10;
            length++;
            width++;
        }
        printf("%d\n",width);
        scanf("%d",&n);
    }
    return 0;
}