#include <stdio.h>
#include <math.h>

bool prime[1000001]={0};

int Count(int n,int k)
{
    int count=0;
    while (n=n/k)
        count+=n;
    return count;
}

int main()
{
    int n;
    int i,j;
    int count;
    int flag;
    int temp;

    for (i=2;i<=1000;i++)
    {
        while (prime[i]&&i<=1000)
            i++;
        temp=i*i;
        for (j=i;temp<=1000000;j++)
        {
            temp=i*j;
            prime[temp]=1;
        }
    }

    while (scanf("%d",&n)==1)
    {
        if (n==0)
            break;
        if (n==1)
            printf("1=1");
        flag=0;
        for (i=2;i<=n;i++)
        {
            while (prime[i] && i<=n)
                i++;
            count=Count(n,i);
            if (count)
            {
                if (flag)
                    printf("*");
                else
                    printf("%d=",n);
                if (count>1)
                {
                    printf("%d^%d",i,count);
                }
                if (count==1)
                {
                    printf("%d",i);
                }
                flag=1;
            }
        }
        printf("\n");
    }
    return 0;
}