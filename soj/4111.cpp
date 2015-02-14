#include <stdio.h>
#include <string.h>

void main()
{
    int t,k;
    int l;
    char string[1010];
    char tar[1010];
    char c;
    int ans;
    int flag;
    int i;
    scanf("%d",&t);
    scanf("%c",&c);
    for (k=0;k<t;k++)
    {
        l=0;
        scanf("%c",&c);
        while (c!='\n'&&c!=' ')
        {
            string[l++]=c;
            scanf("%c",&c);
        }
        for (ans=1;ans<=l;ans++)
        {
            if (!(l%ans))
            {
                flag=1;
                for (i=0;i<ans;i++)
                {
                    tar[i]=string[i];
                }
                for (i=ans;i<l;i++)
                {
                    if (string[i]!=tar[i%ans])
                    {
                        flag=0;
                        break;
                    }
                }
                if (flag)
                {
                    printf("%d\n",l/ans);
                    break;
                }
            }
        }
    }
}