#include <stdio.h>
#include <string.h>
#define N 26
void main()
{
    int n,i,head,flag,count;
    char a,b;
    int u,v;
    short cmp[N][N],exist[N];
    scanf("%d",&n);
    while (n!=0)
    {
        memset(cmp,0,sizeof(cmp));
        memset(exist,0,sizeof(exist));
        getchar();
        for (i=0;i<n;i++)
        {
            a=getchar();
            getchar();
            b=getchar();
            getchar();
            u=a-65;
            v=b-65;
            exist[u]=1;
            exist[v]=1;
            cmp[u][v]=1;
            cmp[v][u]=-1;
        }
        count=0;
        for (i=0;i<N;i++)
            if (exist[i])
                count++;
        while (count>1)
        {
            for (u=0;u<N;u++)
            {
                if (exist[u])
                {
                    flag=1;
                    for (v=0;v<N;v++)
                        if (cmp[u][v]<0)
                        {
                            flag=0;
                            break;
                        }
                    if (flag)
                    {
                        head=u;
                        break;
                    }
                }
            }
            printf("%c ",head+65);
            exist[head]=0;
            for (i=0;i<N;i++)
            {
                cmp[i][head]=0;
                cmp[head][i]=0;
            }
            count--;
        }
        for (i=0;i<N;i++)
            if (exist[i])
                printf("%c\n",i+65);        
        scanf("%d",&n);
    }
}

