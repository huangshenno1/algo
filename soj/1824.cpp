#include <stdio.h>

int p[30010];
int num[30010];

int find(int n)
{
    if (n!=p[n])
    p[n]=find(p[n]);
    return p[n];
}

int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)==2)
    {
        if (n==0&&m==0)
            break;
        for (int i=0;i<30010;i++)
        {
            p[i]=i;
            num[i]=1;
        }
        for (int i=0;i<m;i++)
        {
            int k,a,b;
            scanf("%d",&k);
            scanf("%d",&a);
            for (int j=1;j<k;j++)
            {
                scanf("%d",&b);
                a=find(a);
                b=find(b);
                if (a==b);
                else if (b==0)
                {
                    p[a]=b;
                    num[b]+=num[a];
                }
                else
                {
                    p[b]=a;
                    num[a]+=num[b];    
                }
                a=b;
            }
        
        }
        printf("%d\n",num[find(0)]);
    }
    return 0;
}