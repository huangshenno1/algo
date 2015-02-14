#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DATA
{
    int x,y;
}pre[10001];

int cmp(const void *a,const void *b)
{
    struct DATA *temp1=(struct DATA *)a;
    struct DATA *temp2=(struct DATA *)b;
    return temp1->x-temp2->x;
}

int a[10001];
bool b[10001];

int main()
{
    int n;
    int i,t,c;
    long long ans,exchange;
    while (scanf("%d",&n)==1)
    {    
        memset(b,0,sizeof(b));
        ans=exchange=0;
        for (i=1;i<=n;i++)
        {
            scanf("%d",&pre[i].x);
            pre[i].y=i;
        }
        qsort(pre+1,n,sizeof(struct DATA),cmp);
        for (i=1;i<=n;i++)
        {
            ans=ans+pre[i].x*i;
            a[pre[i].y]=i;
        }
        for (i=1;i<=n;i++)
        {
            if (b[i])
                continue;
            t=a[i];
            b[i]=1;
            c=1;
            while (t!=i)
            {
                b[t]=1;
                t=a[t];
                c++;
            }
            if (c==2 && exchange==0)
                exchange=1;
            if (c>2)
                exchange=2;
        }
        printf("%lld\n%lld\n",ans,exchange);
    }
    return 0;
}