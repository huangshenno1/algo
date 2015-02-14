#include <stdio.h>
#include <string.h>

int main()
{
    int t;
    scanf("%d",&t);
    for (int iCase=0;iCase<t;iCase++)
    {
        char s[1010];
        scanf("%s",s);
        int l=strlen(s);
        int count_starmark=0,count_questionmark=0;
        for (int i=0;i<l;i++)
        {
            if (s[i]=='*')
                count_starmark++;
            else if (s[i]=='?')
                count_questionmark++;
            else
            {
                if (count_starmark)
                    printf("*");
                for (int j=0;j<count_questionmark;j++)
                    printf("?");
                printf("%c",s[i]);
                count_starmark=0;
                count_questionmark=0;
            }
        }
        if (count_starmark)
            printf("*");
        for (int j=0;j<count_questionmark;j++)
            printf("?");
        printf("\n");
    }
    return 0;
}