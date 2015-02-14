#include <stdio.h>

int CommonDivisor(int a,int b)
{
    if (a<b)
    {
        int t=a;
        a=b;
        b=t;
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

int Length(int n)
{
    int l=0;
    while (n)
    {
        l++;
        n/=10;
    }
    return l;
}

int main()
{
    int iCase=0;
    int n;
    scanf("%d",&n);
    while (n)
    {
        iCase++;
        printf("Case %d:\n",iCase);
        int sum=0,num;
        bool minus=0;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&num);
            sum+=num;
        }
        if (sum<0)
        {
            minus=1;
            sum=-sum;
        }
        if (!(sum%n))
        {
            int average=sum/n;
            if (minus)
                printf("- ");
            printf("%d\n",average);
        }
        else if ((double)sum/n<1)
        {
            int denominator,numerator;
            int l_denominator,l_numerator;
            denominator=n/CommonDivisor(sum,n);
            numerator=sum/CommonDivisor(sum,n);
            l_denominator=Length(denominator);
            l_numerator=Length(numerator);
            if (minus)
                printf("  ");
            for (int i=0;i<l_denominator-l_numerator;i++)
            {
                printf(" ");
            }
            printf("%d\n",numerator);
            if (minus)
                printf("- ");
            for (int i=0;i<l_denominator;i++)
            {
                printf("-");
            }
            printf("\n");
            if (minus)
                printf("  ");
            printf("%d\n",denominator);
        }
        else
        {
            int denominator,numerator,integer;
            int l_denominator,l_numerator,l_integer;
            denominator=n/CommonDivisor(sum,n);
            numerator=sum/CommonDivisor(sum,n);
            integer=numerator/denominator;
            numerator=numerator%denominator;
            l_denominator=Length(denominator);
            l_numerator=Length(numerator);
            l_integer=Length(integer);
            if (minus)
                printf("  ");
            for (int i=0;i<l_denominator+l_integer-l_numerator;i++)
            {
                printf(" ");
            }
            printf("%d\n",numerator);
            if (minus)
                printf("- ");
            printf("%d",integer);
            for (int i=0;i<l_denominator;i++)
            {
                printf("-");
            }
            printf("\n");
            if (minus)
                printf("  ");
            for (int i=0;i<l_integer;i++)
            {
                printf(" ");
            }
            printf("%d\n",denominator);
        }
        scanf("%d",&n);
    }
    return 0;
}