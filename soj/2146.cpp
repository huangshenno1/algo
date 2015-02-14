#include <stdio.h>

int main()
{
    char str[15];
    while (scanf("%s",str)==1)
    {
        int s=0,m;
        for (int i=0;i<10;i++)
        {
            if (str[i]=='X')
            {
                s+=10;
            }
            else if (str[i]=='?')
            {
                m=10-i;
            }
            else
            {
                s+=(10-i)*(str[i]-'0');
            }
        }
        for (int i=0;i<=10;i++)
        {
            if (!((s+i*m)%11))
            {
                if (m!=1&&i==10)
                    printf("-1\n");
                else if (m==1&&i==10)
                    printf("X\n");
                else printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}