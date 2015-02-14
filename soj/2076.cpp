#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int *)b-*(int *)a;
}

int main()
{
    int m,n;
    int num[50];
    int iCase=1;
    while (scanf("%d%d",&m,&n))
    {
        if (m==0 && n==0)
            break;
        for (int i=0;i<n;i++)
            scanf("%d",&num[i]);
        qsort(num,n,sizeof(int),cmp);
        int temp=m*n;
        int count=0;
        int k=0;
        int t=0;
        while (k<n && t<n-k && count<n)
        {
            if (temp==num[k])
            {
                if (t)
                    t--;
                else count++;
                k++;
            }
            else
            {
                t++;
            }
            temp--;
        }
        printf("Case %d: %d\n",iCase,count);
        iCase++;
    }
}