#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char s[100];
    while (!feof(stdin))
    {
        scanf("%s",s);
        int len=strlen(s);
        for (int i=0;i<len;i++)
        {
            if (isalpha(s[i]))
                s[i]=toupper(s[i]);
        }
        printf("%s\n",s);
    }
    return 0;
}