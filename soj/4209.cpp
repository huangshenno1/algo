#include <stdio.h>

int main()
{
    int t;
    int b[21];
    int m;
    int i,j;
    int count;
    int flag;
    scanf("%d",&t);
    while (t--)
    {
        count=0;
        scanf("%d",&m);
        for (i=0;i<m;i++)
            scanf("%d",&b[i]);
        for (i=0;i<m-1;i++)
        {
            flag=1;
            for (j=0;j<m-i;j++)
            {
                if (b[j]!=0)
                {
                    flag=0;
                    break;
                }
            }
            if (flag)
                break;
            for (j=0;j<m-i-1;j++)
            {
                b[j]=b[j+1]-b[j];
            }
            count++;
        }
        if (i==m-1)
        {
            if (b[0]==0)
            {
                flag=1;
            }
            else if (b[0]>0)
                flag=2;
            else flag=3;
        }
        if (flag==1)
        {
            for (i=0;i<count;i++)
                printf("z");
            printf("ap!\n");
        }
        if (flag==2)
            printf("*fizzle*\n");
        if (flag==3)
            printf("*bunny*\n");
    }
    return 0;
}