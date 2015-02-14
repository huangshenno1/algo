#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    while (gets(str))
    {
        int l=strlen(str);
        double GPA=0;
        int count=0;
        bool flag=1;
        for (int i=0;i<l;i++)
        {
            if (str[i]==' ')
                continue;
            else if (str[i]>='A'&&str[i]<='D')
            {
                GPA+='E'-str[i];
                count++;
            }
            else if (str[i]=='F')
                count++;
            else flag=0;
        }
        if (flag)
            printf("%.2lf\n",GPA/count);
        else printf("Unknown letter grade in input\n");
    }
    return 0;
}