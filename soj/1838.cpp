#include <stdio.h>
#include <string.h>

int main()
{
    while (1)
    {
        char s[1000010];
        scanf("%s",s);
        if (s[0]=='.')
            break;
        int len=strlen(s);
        bool mark=0;
        for (int m=1;m<=len/2;m++)
        {
            bool flag=1;
            if (len%m)
                continue;
            for (int i=0;i<len;i++)
            {
                if (s[i]!=s[i%m])
                {
                    flag=0;
                    break;
                }
            }
            if (flag)
            {
                printf("%d\n",len/m);
                mark=1;
                break;
            }
        }
        if (!mark)
        {
            printf("1\n");
        }
    }
    return 0;
}