#include <stdio.h>
#include <string.h>

#define R 19871118
#define MAX 105
#define BASE 10000

int a[505][1005];
long long c[1005];

long long Pow(long long x,long long y)
{
    long long ret=1;
    while (y)
    {
        if (y&1)
            ret=x*ret%R;
        x=x*x%R;
        y>>=1;
    }
    return ret;
}

void multiply(int a[],int max,int b)
{
    int i,array=0;
    for (i = max-1; i >= 0; i--)
    {
        array += b * a[i];
        a[i] = array % BASE;
        array /= BASE;
    }
}

void divide(int a[], int max, int b)
{
    int i, div = 0;
    for (i = 0; i < max; i++)
    {
        div = div * BASE + a[i];
        a[i] = div / b;
        div %= b;
    }
}

void combinatorics(long long m)
{
    int i,j;
    memset(a[0],0,MAX*sizeof(int));
    a[0][MAX-1]=1;
    for (i=1; i<=m/2; i++)
    {
        memcpy(a[i], a[i-1], MAX * sizeof(int));
        multiply(a[i], MAX, m+1-i);
        divide(a[i], MAX, i);
    }
    for(i=0;i<=m/2;i++)
    {
        for(j=0;j<MAX && a[i][j]==0;j++);
        long long temp=a[i][j];
        j++;
        for(;j<MAX;j++)
            temp=(temp*10000+a[i][j])%R;
        c[i]=temp;
    }
    for(i=0;i<=m/2;i++)
        c[m-i]=c[i];
}

int Symbol(int i)
{
    if (i&1)
        return -1;
    else return 1;
}

long long Mul(long long x,long long y,long long z)
{
    return ((x*y)%R*z)%R;
}

int main()
{
    long long n,m;
    long long ans;
    int i;
    while (scanf("%lld%lld",&n,&m)==2)
    {
        if (m>n)
        {
            printf("0\n");
            continue;
        }
        combinatorics(m);
        ans=0;
        for (i=0;i<=m;i++)
        {
            ans=(ans+Symbol(i)*Mul(c[i],m-i,Pow(m-i-1,n-1))+R)%R;
        }
        printf("%lld\n",ans);
    }
    return 0;
}