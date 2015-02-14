#include <stdio.h>
#include <string.h>

int main()
{
    char str[110];
    while (gets(str))
    {
        if (!strcmp(str,"END"))
            break;
        int l=strlen(str);
        int count_left_bracket=0,count_depth=0,count_element=1;
        bool state=0;
        char last;
        for (int i=0;i<l;i++)
        {
            if (str[i]==' ')
                continue;
            if (str[i]=='(')
            {
                count_left_bracket++;
                if (count_left_bracket>count_depth)
                    count_depth=count_left_bracket;
                if (count_left_bracket==1)
                    state=1;
                if (count_left_bracket==2)
                    state=0;
            }
            if (str[i]==')')
            {
                count_left_bracket--;
                if (count_left_bracket==0&&last=='(')
                    count_element=0;
                if (count_left_bracket==1)
                    state=1;
            }
            if (state&&str[i]==',')
                count_element++;
            last=str[i];
        }
        printf("%d %d\n",count_element,count_depth);
    }
    return 0;
}