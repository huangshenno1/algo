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

int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        int r=GCD(a,b);
        int tr=r/2;
        int count=1,temp;
        for (int i=2;i<=tr;i++)
        {
            if (r%i==0)
            {
                temp=1;
                while (r%i==0)
                {
                    r=r/i;
                    temp++;
                }
                count=count*temp;
            }
        }
        if (count==1&&r>1)
            printf("2\n");
        else printf("%d\n",count);
    }
    return 0;
}