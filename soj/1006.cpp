#include <stdio.h>

void main()
{
    char command[11];
    char ch;
    scanf("%s",command);
    while (command[0]=='S')
    {
        ch=getchar();
        ch=getchar();
        while (ch!='\n')
        {
            if (ch>='F'&&ch<='Z')
                ch=ch-5;
            else if (ch>='A'&&ch<='E')
                ch=ch+21;
            putchar(ch);
            ch=getchar();
        }
        scanf("%s",command);
        scanf("%s",command);
        if (command[0]=='S')
            putchar('\n');
    }
}
