#include <stdio.h>
#include <string.h>

int main()
{
    char s[40];
    scanf("%s",s);
    while (s[0]!='#')
    {
        int l,r;
        l=strlen(s);
        scanf("%d",&r);
        for (int i=l-r;i<l;i++)
        {
            printf("%c",s[i]);
        }
        for (int i=0;i<l-r;i++)
        {
            printf("%c",s[i]);
        }
        printf("\n");
        scanf("%s",s);
    }
    return 0;
}