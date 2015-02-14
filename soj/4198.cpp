#include <stdio.h>

typedef long long LL;

int Len(LL n)
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
    LL a,b;
    LL temp,count;
    LL c[20];
    LL ans;
    int iCase=1;
    int i,j,k;
    int l;
    while (scanf("%lld%lld",&a,&b)==2 && (a||b))
    {
        ans=a*b;
        l=Len(ans);
        temp=b;
        i=0;
        count=0;
        while (temp)
        {
            if (temp%10==0)
                c[i++]=0;
            else
            {
                c[i++]=(temp%10)*a;
                count++;
            }
            temp/=10;
        }
        printf("Problem %d\n",iCase++);
        for (j=0;j<(l-Len(a));j++)
            printf(" ");
        printf("%lld\n",a);
        for (j=0;j<(l-Len(b));j++)
            printf(" ");
        printf("%lld\n",b);
        for (j=0;j<l;j++)
            printf("-");
        printf("\n");
        if (count==1)
        {
            printf("%lld\n",ans);
            continue;
        }
        count=0;
        for (j=0;j<i;j++)
        {
            if (c[j]==0)
            {
                count++;
                continue;
            }
            for (k=0;k<(l-Len(c[j])-j);k++)
                printf(" ");
            printf("%lld",c[j]);
            for (k=0;k<count;k++)
                printf("0");
            printf("\n");
            count=0;
        }
        for (j=0;j<l;j++)
            printf("-");
        printf("\n");
        printf("%lld\n",ans);
    }
    return 0;
}