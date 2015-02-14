#include <stdio.h>
#define N 100
int appro(int a,int b)
{
    int t=1;
    if (a==b)
        return a;
    if (a<b)
    {
        t=a;
        a=b;
        b=t;
    }
    while (t)
    {
        t=a%b;
        a=b;
        b=t;
    }
    return a;
}
int times(int a,int b)
{
    return (long long)a*b/appro(a,b);
}
int main()
{
    int m,n,i,j,s;
    int a[N];
    scanf("%d",&m);
    for (j=0;j<m;j++)
    {
        s=1;
        scanf("%d",&n);
        for (i=0;i<n;i++)
            scanf("%d",&a[i]);
        for (i=0;i<n;i++)
            s=times(s,a[i]);
        printf("%d\n",s);
    }
return 0;
}