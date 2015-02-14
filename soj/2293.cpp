#include <stdio.h>

int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)==2)
    {
        int s=0;
        int sum[100010]={0},re_sum[100010]={0};
        for (int t,i=1;i<=n;i++)
        {
            scanf("%d",&t);
            s+=t;
            sum[i]=sum[i-1]+t;
        }
        for (int i=0;i<n;i++)
        {
            re_sum[n-i]=s-sum[i];
        }
        int l;
        bool flag=0;
        for (l=n;l>0;l--)
        {
            for (int i=0;i<=n-l;i++)
            {
                if ((s-sum[i]-re_sum[n-l-i])%m==0)
                {
                    printf("%d\n",l);
                    flag=1;
                    break;
                }
            }
            if (flag)
                break;
        }
        if (l==0)
        {
            printf("0\n");
        }
    }
    return 0;
}