#include <stdio.h>

int main()
{
    char str[80];
    while (gets(str)!=NULL)
    {
        int count_letter[26]={0};
        for (int i=0;str[i]!='\0';i++)
        {
            if (str[i]>='A'&&str[i]<='Z')
            {
                count_letter[str[i]-'A']++;
            }
        }
        gets(str);
        for (int i=0;str[i]!='\0';i++)
        {
            if (str[i]>='A'&&str[i]<='Z')
            {
                count_letter[str[i]-'A']++;
            }
        }
        gets(str);
        for (int i=0;str[i]!='\0';i++)
        {
            if (str[i]>='A'&&str[i]<='Z')
            {
                count_letter[str[i]-'A']++;
            }
        }
        gets(str);
        for (int i=0;str[i]!='\0';i++)
        {
            if (str[i]>='A'&&str[i]<='Z')
            {
                count_letter[str[i]-'A']++;
            }
        }
        int max_count=0;
        for (int i=0;i<26;i++)
        {
            if (count_letter[i]>max_count)
                max_count=count_letter[i];
        }
        for (;max_count>0;max_count--)
        {
            int count_space=0;
            for (int i=0;i<26;i++)
            {
                if (count_letter[i]>=max_count)
                {
                    for (;count_space>0;count_space--)
                        printf(" ");
                    printf("*");
                    count_space++;
                }
                else count_space+=2;
            }
            printf("\n");
        }
        for (int i=0;i<26;i++)
        {
            printf("%c",i+65);
            if (i!=25)
                printf(" ");
            else printf("\n");
        }
    }
    return 0;
}