#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int *)b-*(int *)a;
}

int main()
{
    int numOfCase;
    scanf("%d",&numOfCase);
    for (int iCase=1;iCase<=numOfCase;iCase++)
    {
        int goal,friendNum;
        scanf("%d%d",&goal,&friendNum);
        int friendStamp[1010];
        for (int i=0;i<friendNum;i++)
        {
            scanf("%d",&friendStamp[i]);
        }
        qsort(friendStamp,friendNum,sizeof(int),cmp);
        printf("Scenario #%d:\n",iCase);
        int sum=0;
        bool flag=0;
        for (int i=0;i<friendNum;i++)
        {
            sum+=friendStamp[i];
            if (sum>=goal)
            {
                flag=1;
                printf("%d\n\n",i+1);
                break;
            }
        }
        if (!flag)
            printf("impossible\n\n");
    }
    return 0;
}