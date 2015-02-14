#include <stdio.h>

#define MAX 2000000000

int Min(int a,int b)
{
    return a<b?a:b;
}

int main()
{
    int f[10001];
    int t,n;
    int k,h[10000],s[10000];
    int i,j;
    int sum_h,sum_s,score;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%d",&k,&n);
        sum_h=sum_s=0;
        for (i=0;i<n;i++)
        {
            scanf("%d%d",&h[i],&s[i]);
            sum_h+=h[i];
            sum_s+=s[i];
        }
        if (sum_h<=k)
        {
            printf("0\n");
            continue;
        }
        f[0]=0;
        for (i=1;i<=10000;i++)
            f[i]=MAX;
        for (i=0;i<n;i++)
        {
            for (j=10000;j>=0;j--)
            {
                if (j>=h[i])
                    f[j]=Min(f[j],f[j-h[i]]+s[i]);
            }
        }
        score=MAX;
        for (i=k;i<=10000;i++)
        {
            if (score>f[i])
                score=f[i];
        }
        printf("%d\n",sum_s-score);
    }
    return 0;
}