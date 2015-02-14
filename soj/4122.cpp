#include <stdio.h>
#include <string.h>

int a[200010],b[200010];

int main()
{

    int t,cas;
    scanf("%d",&t);
    for (cas=0;cas<t;cas++)
    {
        int q;
        int n,m;
        int i;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        scanf("%d%d",&n,&m);
        for (i=0;i<n;i++)
        {
            int ta,tb;
            scanf("%d%d",&ta,&tb);
            a[ta+100000]++;
            b[tb+100000]++;
        }
        for (i=0;i<200000;i++)
        {
            a[i+1]+=a[i];
            b[i+1]+=b[i];
        }
        for (i=1;i<200001;i++)
        {
            a[i]-=b[i-1];
        }
        for (i=0;i<m;i++)
        {

            scanf("%d",&q);
            printf("%d\n",a[q+100000]);
        }
    }
    return 0;
}