#include <stdio.h>
#include <string.h>

#define MAX 0xfffffff

char str[201][11];

int distance[201][201];
int n;

void Floyd()
{
    for (int k=1;k<=n;k++)
    {
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                if (distance[i][j]>distance[i][k]+distance[k][j])
                    distance[i][j]=distance[i][k]+distance[k][j];
            }
        }
    }
}

int main()
{
    int i,j,k,l;
    char str1[11],str2[11];
    n=0;
    while (scanf("%s",str[++n])==1)
    {
        if (str[n][0]=='*')
        {
            n--;
            break;
        }
    }
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            if (i==j)
                distance[i][j]=0;
            else
            {
                int len1=strlen(str[i]);
                int len2=strlen(str[j]);
                if (len1==len2)
                {
                    int count=0;
                    for (k=0;k<len1;k++)
                    {
                        if (str[i][k]!=str[j][k])
                            count++;
                    }
                    if (count==1)
                    {
                        distance[i][j]=distance[j][i]=1;
                        continue;
                    }
                }
                distance[i][j]=MAX;
            }
        }
    }

    Floyd();

    while (scanf("%s%s",str1,str2)==2)
    {
        for (i=1;i<=n;i++)
        {
            if (!strcmp(str1,str[i]))
                break;
        }
        for (j=1;j<=n;j++)
        {
            if (!strcmp(str2,str[j]))
                break;
        }
        if (distance[i][j]==MAX)
            printf("Impossible\n");
        else
            printf("%s %s %d\n",str1,str2,distance[i][j]);
    }
    printf("\n");
    return 0;
}