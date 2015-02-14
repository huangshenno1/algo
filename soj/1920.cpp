#include <stdio.h>
#include <string.h>

int main()
{
    char buf[90],str[90];
    while (gets(buf))
    {
        if (!strcmp(buf,"THE END."))
            break;
        int l_buf=strlen(buf);
        int l=0;
        for (int i=0;i<l_buf;i++)
        {
            if (buf[i]>='a'&&buf[i]<='z')
                str[l++]=buf[i];
            else if (buf[i]>='A'&&buf[i]<='Z')
                str[l++]=buf[i]+32;
        }
        bool flag=1;
        for (int i=0;i<l/2;i++)
        {
            if (str[i]!=str[l-1-i])
            {
                flag=0;
                break;
            }
        }
        if (flag)
            printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}