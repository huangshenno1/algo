#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int *)b-*(int *)a;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int iCase=0;iCase<t;iCase++)
    {
        int num[1010];
        int i;
        int n;
        scanf("%d",&n);
        for (i=0;i<n;i++)
        {
            scanf("%d",&num[i]);
        }
        if (n==1)
            printf("%d\n",num[0]);
        else
        {
            qsort(num,n,sizeof(int),cmp);
            int s=0;
            bool flag=1;
            int l=0,h=n-1;
            for (i=0;i<n-1;)
            {
                if (num[i]>1&&num[i+1]>1)
                {
                    s+=num[i]*num[i+1];
                    i+=2;
                }
                else
                {
                    break;
                }
            }
            l=i;
            for (i=n-1;i>0;)
            {
                if (num[i]<1&&num[i-1]<1)
                {
                    s+=num[i]*num[i-1];
                    i-=2;
                }
                else
                {
                    break;
                }
            }
            h=i;
            for (int i=l;i<=h;i++)
            {
                s+=num[i];
            }
            printf("%d\n",s);
        }
    }
    return 0;
}