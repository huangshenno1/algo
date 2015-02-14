#include <stdio.h>
#include <stdlib.h>

int comp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}

int main()
{
    while (!feof(stdin))
    {
        int sequence[3000];
        int difference[3000];
        int l;
        scanf("%d",&l);
        for (int i=0;i<l;i++)
        {
            scanf("%d",&sequence[i]);
            if (i)
                difference[i-1]=abs(sequence[i]-sequence[i-1]);
        }
        qsort(difference,l-1,sizeof(int),comp);
        bool flag=1;
        for (int i=0;i<l-1;i++)
        {
            if (difference[i]!=i+1)
            {
                flag=0;
                break;
            }
        }
        if (flag)
            printf("Jolly\n");
        else printf("Not jolly\n");
    }
    return 0;
}