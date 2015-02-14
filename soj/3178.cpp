#include <stdio.h>
#include <string.h>

int main()
{
    int t;
    scanf("%d",&t);
    for (int iCase=0;iCase<t;iCase++)
    {
        char a[12],b[12],s[12];
        scanf("%s%s",a,b);
        int l_a=strlen(a);
        for (int i=l_a;i<12;i++)
            a[i]='0';
        int l_b=strlen(b);
        for (int i=l_b;i<12;i++)
            b[i]='0';
        int c=0;
        for (int i=0;i<12;i++)
        {
            s[i]=c+a[i]-'0'+b[i]-'0';
            c=s[i]/10;
            s[i]=s[i]%10+'0';
        }
        bool flag=0;
        for (int i=11;i>=0;i--)
        {
            if (flag||s[i]!='0')
            {
                printf("%c",s[i]);
                flag=1;
            }
        }
        printf("\n");
    }
    return 0;
}