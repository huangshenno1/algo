#include <stdio.h>

int GCD(int a,int b)
{
    if (a<b)
    {
        int temp=a;
        a=b;
        b=temp;
    }
    int r=a%b;
    while (r)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

int mini_prime[1000001]={0,1};

int main()
{
    for (int i=2;i<1001;i++)
    {
        if (mini_prime[i]==0)
            mini_prime[i]=i;
        for (int j=i*i;j<1000001;j+=i)
        {
            if (mini_prime[j]==0)
                mini_prime[j]=i;
        }
    }
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        int r=GCD(a,b);
        int count=1,temp;
        while (r!=1)
        {
            temp=1;
            if (mini_prime[r]==0)
                mini_prime[r]=r;
            int cp=mini_prime[r];
            while (mini_prime[r]==cp)
            {
                r=r/cp;
                temp++;
            }
            count*=temp;
        }
        printf("%d\n",count);
    }
    return 0;
}