#include <stdio.h>

int main()
{
    int r,c;
    while (scanf("%d%d",&r,&c)==2)
    {
        char line[60][60];
        int distance[10]={0};
        bool existDistance[60]={0};
        for (int i=0;i<r;i++)
        {
            scanf("%s",line[i]);
            for (int j=1;j<c-3;j++)
            {
                if (line[i][j]>'0'&&line[i][j]<='9'&&distance[line[i][j]-'0']==0)
                {
                    distance[line[i][j]-'0']=c-j;
                    existDistance[c-j]=1;
                }
            }
        }
        for (int i=1;i<=9;i++)
        {
            int count=1;
            for (int j=1;j<distance[i];j++)
            {
                if (existDistance[j])
                    count++;
            }
            printf("%d\n",count);
        }
    }
    return 0;
}