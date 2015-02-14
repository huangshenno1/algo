#include <stdio.h>
#include <string.h>
#define N 100000
int l=1;
void Mul(int a[],int b)
{
    int i,e;
    e=0;
    for (i=0;i<l;i++)
    {
        e=a[i]*b+e;
        a[i]=e%10;
        e/=10;
    }
    while (e)
    {
        a[l++]=e%10;
        e/=10;
    }
}
void Fac(int a[],int n)
{
    int i;
    for (i=1;i<=n;i++)
        Mul(a,i);
}
void main(void)
{
    int m,n,k;
    int i,j;
    int a[N];
    scanf("%d",&m);
    for (i=0;i<m;i++)
    {
        memset(a,0,sizeof(a));
        a[0]=1;
        scanf("%d%d",&n,&k);
        Fac(a,n);
        for (j=0;j<N;j++)
        {
            if (a[j])
                break;
        }
        printf("%d\n",a[k+j-1]);
    }
}
    
