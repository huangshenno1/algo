#include <stdio.h>

#define MAX 0xfffffff

int distance[201][201];
int n,m;

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
    while (scanf("%d%d",&n,&m)==2 && n)
    {
        for (i=0;i<=n;i++)
        {
            for (j=0;j<=n;j++)
            {
                if (i==j)
                    distance[i][j]=0;
                else
                    distance[i][j]=MAX;
            }
        }
        while (m--)
        {
            scanf("%d%d%d",&i,&j,&l);
            if (distance[i][j]>l)
                distance[i][j]=distance[j][i]=l;
        }
        Floyd();
        scanf("%d",&k);
        while (k--)
        {
            scanf("%d%d",&i,&j);
            if (distance[i][j]==MAX)
                printf("pity\n");
            else
                printf("%d\n",distance[i][j]);
        }
        printf("\n");
    }
    return 0;
}