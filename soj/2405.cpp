#include <cstdio>

int main()
{
    int n;
    int a,b;
    int busy[24],ans;
    int i,j;
    while (~scanf("%d",&n))
    {
        for (i=0;i<24;i++)
            busy[i]=0;
        for (i=0;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            for (j=a;j<b;j++)
                busy[j]++;
        }
        for (ans=0,i=0;i<24;i++)
        {
            if (ans<busy[i])
                ans=busy[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}