#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a-*(int *)b;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int iCase=0;iCase<t;iCase++)
    {
        int num[60];
        int l=0;
        int n;
        char c;
        do 
        {
            scanf("%d%c",&n,&c);
            num[l++]=n;
        } while (c!='\n');
        qsort(num,l,sizeof(int),cmp);
        for (int i=0;i<l;i++)
        {
            printf("%d",num[i]);
            if (i<l-1)
                printf(" ");
            else printf("\n");
        }
    }
    return 0;
}