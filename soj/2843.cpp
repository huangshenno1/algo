#include <stdio.h>

int SumOfDigits(int n)
{
    int sum=0;
    while (n)
    {
        sum+=n%10;
        n/=10;
    }
    return sum;
}

int main()
{
    for (int n=1;n<10000;n++)
    {
        int m;
        if (n<19)
            m=9;
        else if (n<118)
            m=18;
        else if (n<1027)
            m=27;
        else m=36;
        bool flag=1;
        for (int i=n-m;i<n;i++)
        {
            if (i+SumOfDigits(i)==n)
            {
                flag=0;
                break;
            }
        }
        if (flag)
            printf("%d\n",n);
    }
    return 0;
}