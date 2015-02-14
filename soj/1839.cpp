#include <stdio.h>
#include <math.h>

int f(int n)
{
    double ans=n;
    int i;
    for (i=2;i<=n;i++)
    {
        if (n%i==0)
        {
            ans=ans*(i-1)/i;
            while (n%i==0)
            {
                n/=i;
            }
        }
    }
    return (int)(ans+0.5);
}

int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        if (n==0)
            break;
        printf("%d\n",f(n));
    }
    return 0;
}