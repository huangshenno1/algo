#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d",&n);
    for (int iCase=1;iCase<=n;iCase++)
    {
        char s[10];
        scanf("%s",s);
        int l=strlen(s);
        int f[3]={9,3,7};
        int id=0,m;
        for (int i=0;i<l;i++)
        {
            if (s[i]=='?')
            {
                m=i;
            }
            else
            {
                id=id+(s[i]-'0')*f[(l-1-i)%3];
            }
        }
        for (int i=0;i<10;i++)
        {
            if ((id+i*f[(l-1-m)%3])%10==0)
            {
                s[m]=i+'0';
                break;
            }
        }
        printf("Scenario #%d:\n",iCase);
        printf("%s\n\n",s);
    }
    return 0;
}