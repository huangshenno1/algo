#include <stdio.h>

bool IsRADAR(int n)
{
    int digit[12];
    int length=0;
    while (n)
    {
        digit[length++]=n%10;
        n/=10;
    }
    for (int i=0;i<length/2;i++)
    {
        if (digit[i]!=digit[length-1-i])
        {
            return 0;
        }
    }
    return 1;
}

int Sum(int n)
{
    int digit[12];
    int sum=0;
    int temp=n;
    int length=0;
    while (n)
    {
        digit[length++]=n%10;
        n/=10;
    }
    for (int i=0;i<length;i++)
    {
        sum=sum*10+digit[i];
    }
    sum+=temp;
    return sum;
}

int main()
{
    int n;
    while (~scanf("%d",&n))
    {
        int count=0;
        while (!IsRADAR(n))
        {
            n=Sum(n);
            count++;
        }
        printf("%d %d\n",count,n);
    }
    return 0;
}