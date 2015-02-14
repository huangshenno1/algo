#include <stdio.h>

int main()
{
    int n;
    char str[1010];
    int i;
    char last;
    int count;
    scanf("%d",&n);
    while (n--)
    {
        scanf("%s",str);
        last=str[0];
        count=1;
        for (i=1;str[i]!='\0';i++)
        {
            if (str[i]==last)
                count++;
            else
            {
                printf("%d%c",count,last);
                count=1;
                last=str[i];
            }
        }
        printf("%d%c\n",count,last);
    }
    return 0;
}
