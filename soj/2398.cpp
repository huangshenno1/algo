#include <stdio.h>
#include <string.h>

int main()
{
    for (int iCase=0;iCase<10;iCase++)
    {
        char num[1010];
        scanf("%s",num);
        int l=strlen(num);
        int s=0;
        for (int i=0;i<l;i++)
        {
            if (i%2)
                s+=(num[i]-'0');
            else
                s-=(num[i]-'0');
        }
        if (!(s%11))
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}