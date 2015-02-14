#include <stdio.h>

int Pow(int n)
{
    long long temp=1;
    long long a=2;
    while (n)
    {
        if (n&1)
            temp*=a;
        a*=a;
        n>>=1;
    }
    while (temp/10)
    {
        temp/=10;
    }
    return (int)temp;
}

int main()
{
    int a,b,e;
    long long temp;
    while (scanf("%d%d",&a,&b)==2)
    {
        for (e=a+1;e<=62;e++)
        {
            if (Pow(e)==b)
                break;
        }
        if (e==63)
            printf("0\n");
        else
            printf("%d\n",e);
    }
    return 0;
}