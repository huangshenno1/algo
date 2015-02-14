#include <stdio.h>

int main()
{
    int lj,p;
    while (scanf("%d%d",&lj,&p)==2)
    {
        int num;
        int s=lj*p;
        for (int i=0;i<5;i++)
        {
            scanf("%d",&num);
            printf("%d",num-s);
            if (i==4)
                putchar('\n');
            else putchar(' ');
        }
    }
    return 0;
}