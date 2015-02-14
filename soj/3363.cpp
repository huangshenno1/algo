#include <cstdio>

int main()
{
    int count[100];
    int a,b,c,i,j,k,l,ans,m;
    while (scanf("%d%d%d",&a,&b,&c)==3)
    {
        l=a+b+c;
        for (i=1;i<=l;i++) count[i]=0;
        for (i=1;i<=a;i++)
            for (j=1;j<=b;j++)
                for (k=1;k<=c;k++)
                    count[i+j+k]++;
        ans=0;m=0;
        for (i=1;i<=l;i++)
        {
            if (count[i]>m)
            {
                m=count[i];
                ans=i;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}