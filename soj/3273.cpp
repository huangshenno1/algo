#include <stdio.h>

bool prime[1001]={0};

int main()
{
    for (int i=2;i<32;i++)
    {
        for (int j=2;i*j<=1000;j++)
        {
            prime[i*j]=1;
        }
    }
    int n,t;
    int count;
    while (scanf("%d",&n)==1&&n)
    {
        if (n==1)
            printf("1 : 0\n");
        else
        {
            t=n;
            count=0;
            for (int i=2;i<1000;i++)
            {
                if (!prime[i]&&n%i==0)
                {
                    while (n%i==0)
                        n/=i;
                    count++;
                }
            }
            if (n!=1)
                count++;
            printf("%d : %d\n",t,count);
        }
    }
    return 0;
}