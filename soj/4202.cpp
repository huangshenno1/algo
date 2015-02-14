#include <stdio.h>
#include <string.h>

int main()
{
    char str[70];
    bool alphabet[26];
    int i;
    bool flag;
    while (gets(str)&&strcmp(str,"END"))
    {
        memset(alphabet,0,sizeof(alphabet));
        flag=1;
        for (i=0;str[i]!='\0';i++)
        {
            if (str[i]>='A'&&str[i]<='Z')
            {
                if (alphabet[str[i]-'A']==1)
                {
                    flag=0;
                    break;
                }
                alphabet[str[i]-'A']=1;
            }
        }
        if (flag)
        {
            puts(str);
        }
    }
    return 0;
}