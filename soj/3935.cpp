#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    for (int iCase=0;iCase<t;iCase++)
    {
        int n;
        scanf("%d",&n);
        long long max=0;
        long long ability=0;
        int a;
        bool flag=1;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&a);
            if (flag)
            {
                ability+=a;
                long long temp=ability*(n-1-i);
                if (temp>max)
                    max=temp;
                else
                    flag=0;
            }
        }
        printf("%lld\n",max);
    }
    return 0;
}