#include <stdio.h>
#include <string.h>

int main()
{
    char str[110];
    while (scanf("%s",str)==1)
    {
        if (str[0]=='$')
            break;
        int l=strlen(str);
        for (int i=0;i<l;i++)
        {
            str[i]=(str[i]-'A'-i-1+130)%26+'A';
        }
        printf("%s\n",str);
    }
    return 0;
}