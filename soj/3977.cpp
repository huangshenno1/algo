#include <stdio.h>
#include <string.h>

int main()
{
    char blimp[5][12];
    while (scanf("%s%s%s%s%s",blimp[0],blimp[1],blimp[2],blimp[3],blimp[4])==5)
    {
        bool flag=0;
        bool CIA[5]={0};
        for (int k=0;k<5;k++)
        {
            int l=strlen(blimp[k]);
            for (int i=0;i<l-2;i++)
            {
                if (blimp[k][i]=='F'&&blimp[k][i+1]=='B'&&blimp[k][i+2]=='I')
                {
                    CIA[k]=1;
                    flag=1;
                    break;
                }
            }
        }
        if (!flag)
            printf("HE GOT AWAY!\n");
        else
        {
            int count=0;
            for (int i=0;i<5;i++)
            {
                if (CIA[i])
                {
                    if (count)
                        putchar(' ');
                    printf("%d",i+1);
                    count++;
                }
            }
            putchar('\n');
        }
    }
    return 0;
}