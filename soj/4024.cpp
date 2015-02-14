#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char sentence[1100];
    int i;
    char symbol;
    bool flag;
    bool status;
    while (gets(sentence))
    {
        if (sentence[0]=='*')
            break;
        flag=1;
        status=0;
        symbol=toupper(sentence[0]);
        for (i=0;sentence[i]!='\0';i++)
        {
            if (status==0)
            {
                if (toupper(sentence[i])!=symbol)
                {
                    flag=0;
                    break;
                }
                status=1;
            }
            else
            {
                if (sentence[i]==' ')
                    status=0;
            }
        }
        if (flag)
            printf("Y\n");
        else printf("N\n");
    }
    return 0;
}