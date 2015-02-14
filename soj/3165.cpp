#include <cstdio>
#include <cstring>

int t,n,m;
long long a,b;
char x[1010];

int main()
{
    scanf("%d",&t);
    while (t--)
    {
        scanf("%s %d %d",x,&n,&m);
        a=0;
        for (int i=0;x[i]!='\0';i++)
            a=(a*10+x[i]-48)%m;
        b=1;
        while (n)
        {
            if (n&1)
                b=(b*a)%m;
            a=(a*a)%m;
            n>>=1;
        }
        printf("%lld\n",b);
    }
    return 0;
}