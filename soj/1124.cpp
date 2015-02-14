#include <stdio.h>
#include <string.h>

void Sum(int digit[],int &l,int r)
{
    int sum[100];
    int e=0;
    for (int i=0;i<l;i++)
    {
        sum[i]=digit[i]+digit[l-1-i]+e;
        e=sum[i]/r;
        sum[i]=sum[i]%r;
    }
    for (int i=0;i<l;i++)
    {
        digit[i]=sum[i];
    }
    if (e)
    {
        digit[l++]=e;
        digit[l]='\0';
    }
}

bool Right(int digit[],int l)
{
    bool flag=1;
    for (int i=0;i<l/2;i++)
    {
        if (digit[i]!=digit[l-1-i])
        {
            flag=0;
            break;
        }
    }
    return flag;
}

int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n;
        char str[100];
        scanf("%d%s",&n,str);
        int l=strlen(str);
        int digit[100];
        for (int i=0;i<l;i++)
        {
            if (str[i]>='0'&&str[i]<='9')
                digit[i]=str[i]-'0';
            else digit[i]=str[i]-'A'+10;
        }
        digit[l]='\0';
        int count=0;
        while (!Right(digit,l))
        {
            count++;
            if (count>30)
            {
                count=0;
                break;
            }
            Sum(digit,l,n);
        }
        printf("%d\n",count);
    }
    return 0;
}