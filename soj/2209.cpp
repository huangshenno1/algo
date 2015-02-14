#include <cstdio>
#include <cstring>

const int maxn = 100;

struct BigInteger
{
    int digit[maxn];
    BigInteger() {memset(digit,0,sizeof(digit));}
    BigInteger(int num) {memset(digit,0,sizeof(digit)); int i=0; while (num){digit[i++]=num%10; num/=10;}}
    void print()
    {
        int i;
        for (i=maxn-1;i>=0;i--)
            if (digit[i]!=0) break;
        for (;i>=0;i--)
            printf("%d",digit[i]);
        printf("\n");
    }
}f[255];

BigInteger plus(BigInteger a, BigInteger b)
{
    BigInteger c = BigInteger();
    for (int i=0,e=0;i<maxn;i++)
    {
        c.digit[i]=a.digit[i]*2+b.digit[i]+e;
        e=c.digit[i]/10;
        c.digit[i]=c.digit[i]%10;
    }
    return c;
}

int main()
{
    f[0]=f[1]=BigInteger(1);
    for (int i=2;i<=250;i++)
    {
        f[i]=plus(f[i-2],f[i-1]);
    }

    int n;
    while (scanf("%d",&n)==1)
        f[n].print();
    return 0;
}