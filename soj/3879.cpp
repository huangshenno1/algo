#include <stdio.h>

int f(int a,int b)
{
    int s=a^b;
    int count=0;
    while (s)
    {
        count+=s%2;
        s/=2;
    }
    return count;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int iCase=0;iCase<t;iCase++)
    {
        int m,n;
        scanf("%d%d",&m,&n);
        int a[100],b[100];
        for (int i=0;i<m;i++)
            scanf("%d",&a[i]);
        for (int i=0;i<n;i++)
        {
            int min=10;
            int num=1000000;
            scanf("%d",&b[i]);
            for (int j=0;j<m;j++)
            {
                int temp=f(a[j],b[i]);
                if (temp<min)
                {
                    min=temp;
                    num=a[j];
                }
                else if (temp==min)
                {
                    if (a[j]<num)
                        num=a[j];
                }
            }
            printf("%d\n",num);
        }
    }
    return 0;
}