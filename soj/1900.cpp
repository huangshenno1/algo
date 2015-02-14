#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    for (int iCase=0;iCase<n;iCase++)
    {
        char string[50];
        scanf("%s",&string);
        for (int i=0;i<4;i++)
        {
            int field=0;
            for (int j=0;j<8;j++)
            {
                field=field*2+string[8*i+j]-'0';
            }
            printf("%d",field);
            if (i<3)
                printf(".");
        }
        printf("\n");
    }
    return 0;
}