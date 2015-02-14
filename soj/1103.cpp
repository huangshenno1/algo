#include <stdio.h>
#include <string.h>

int main()
{
    char IP[40];
    scanf("%s",IP);
    while (1)
    {
        if (feof(stdin))
            break;
        int len=strlen(IP);    
        int flag=0;
        int mark=1;
        int field=0;
        int count=0;
        for (int i=0;i<len;i++)
        {
            if (IP[i]=='.'&&flag%2)
            {
                field=0;
                flag=0;
                count++;
            }
            else if (IP[i]>='0'&&IP[i]<='9')
            {
                field=field*10+IP[i]-'0';
                if (field>255)
                {
                    printf("NO\n");
                    mark=0;
                    break;
                }
                flag=1;
            }
            else
            {
                printf("NO\n");
                mark=0;
                break;
            }
        }
        if (count!=3&&mark)
        {
            printf("NO\n");
            mark=0;
        }
        if (mark)
        {
            printf("YES\n");
        }
        scanf("%s",IP);
    }
    return 0;
}