#include <stdio.h>

bool prime[1000000]={0};

int main()
{
    for (int i=2;i<1000;i++)
    {
        for (int j=i;i*j<1000000;j++)
        {
            prime[i*j]=1;
        }
    }
    int n;
    int a,t;
    bool flag;
    while (scanf("%d",&n)==1 && n)
    {
        flag=0;
        t=n/2;
        for (a=3;a<=t;a++)
        {
            if (!prime[a]&&!prime[n-a])
            {
                flag=1;
                break;
            }
        }
        if (flag)
            printf("%d = %d + %d\n",n,a,n-a);
        else
            printf("Goldbach's conjecture is wrong.\n");
    }
    return 0;
}