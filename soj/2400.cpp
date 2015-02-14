#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d",&n);
    for (int iCase=0;iCase<n;iCase++)
    {
        char s[1000];
        scanf("%s",s);
        int l=strlen(s);
        int i;
        for (i=0;i<l-3;i++)
        {
            if (s[i]=='L'&&s[i+1]=='O'&&s[i+2]=='V'&&s[i+3]=='E')
            {
                printf("LOVE\n");
                break;
            }
        }
        if (i==l-3)
            printf("SINGLE\n");
    }
    return 0;
}