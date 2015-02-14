#include <stdio.h>
#include <string.h>

int ConvertToInteger(char str[],int l)
{
    int s=0;
    for (int i=0;i<l;i++)
    {
        s=s*10+str[i]-'0';
    }
    return s;
}

int main()
{
    char a[10],b[10];
    while (scanf("%s%s",a,b)==2)
    {
        int la=strlen(a);
        int lb=strlen(b);
        for (int i=0;i<la;i++)
        {
            if (a[i]=='6')
                a[i]='5';
        }
        for (int i=0;i<lb;i++)
        {
            if (b[i]=='6')
                b[i]='5';
        }
        printf("%d ",ConvertToInteger(a,la)+ConvertToInteger(b,lb));
        for (int i=0;i<la;i++)
        {
            if (a[i]=='5')
                a[i]='6';
        }
        for (int i=0;i<lb;i++)
        {
            if (b[i]=='5')
                b[i]='6';
        }
        printf("%d\n",ConvertToInteger(a,la)+ConvertToInteger(b,lb));
    }
    return 0;
}