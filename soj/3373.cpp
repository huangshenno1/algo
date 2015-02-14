#include <stdio.h>
#include <string.h>

int main()
{
    char str[50];
    int l, cnt, i;
    while (gets(str) && str[0] != '#')
    {
        l = strlen(str) - 1;
        cnt = 0;
        for (i=0;i<l;i++)
            if (str[i] == '1') cnt++;
        if (str[l] == 'o')
        {
            if (cnt & 1) str[l] = '0';
            else str[l] = '1';
        }
        else
        {
            if (cnt & 1) str[l] = '1';
            else str[l] = '0';
        }
        puts(str);
    }
    return 0;
}
