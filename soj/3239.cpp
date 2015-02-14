#include <stdio.h>
#include <string.h>

int main()
{
    int t;
    scanf("%d",&t);
    for (int iCase=1;iCase<=t;iCase++)
    {
        int m;
        char letter[81];
        scanf("%d%s",&m,letter);
        m--;
        int l=strlen(letter);
        printf("%d ",iCase);
        for (int i=0;i<l;i++)
        {
            if (i!=m)
                putchar(letter[i]);
        }
        putchar('\n');
    }
    return 0;
}