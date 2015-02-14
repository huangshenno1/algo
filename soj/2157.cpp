#include <stdio.h>
#include <ctype.h>

int main()
{
    char decryptionKey[30];
    while (scanf("%s",decryptionKey)==1)
    {
        char c;
        scanf("%c",&c);
        while (c=='\r'||c=='\n')
            scanf("%c",&c);
        while (c!='\r'&&c!='\n')
        {
            if (c>='a'&&c<='z')
            {
                c=decryptionKey[c-'a'];
            }
            if (c>='A'&&c<='Z')
            {
                c=toupper(decryptionKey[c-'A']);
            }
            printf("%c",c);
            scanf("%c",&c);
        }
        printf("\n");
    }
    return 0;
}