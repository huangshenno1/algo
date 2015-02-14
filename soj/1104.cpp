#include <stdio.h>

int main()
{
    int l,a,b,s;
    int last,count_9=0;
    scanf("%d",&l);
    scanf("%d%d",&a,&b);
    last=a+b;
    l--;
    while (l--)
    {
        scanf("%d%d",&a,&b);
        s=a+b;
        if (s>9)
        {
            printf("%d",last+1);
            for (int i=0;i<count_9;i++)
                printf("0");
            count_9=0;
            last=s%10;
        }
        else if (s<9)
        {
            printf("%d",last);
            for (int i=0;i<count_9;i++)
                printf("9");
            count_9=0;
            last=s%10;
        }
        else
        {
            count_9++;
        }
    }
    if (s!=9)
    {
        printf("%d\n",last);
    }
    else
    {
        printf("%d",last);
        for (int i=0;i<count_9;i++)
            printf("9");
    }
    return 0;
}