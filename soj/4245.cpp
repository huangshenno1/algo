#include <cstdio>

const int mod = 987654321;

struct Matrix
{
    long long elem[2][2];
    Matrix(long long a=0, long long b=0, long long c=0, long long d=0)
    {
        elem[0][0] = a;
        elem[0][1] = b;
        elem[1][0] = c;
        elem[1][1] = d;
    }
};

Matrix mul(Matrix a, Matrix b)
{
    Matrix c;
    for (int i=0;i<2;i++)
        for (int j=0;j<2;j++)
            for (int k=0;k<2;k++)
                c.elem[i][j]=(c.elem[i][j]+a.elem[i][k]*b.elem[k][j])%mod;
    return c;
}

Matrix pow(Matrix a, int n)
{
    Matrix c(1,0,0,1);
    while (n)
    {
        if (n&1) c=mul(c,a);
        a=mul(a,a);
        n>>=1;
    }
    return c;
}

int main()
{
    int n;
    while (~scanf("%d",&n) && n)
    {
        if (n&1 || n<8) {puts("0"); continue;}
        Matrix a(1,1,1,0);
        Matrix c = pow(a, n-4);
        long long ans = c.elem[0][0] - n/2 + 1;
        ans = ans % mod;
        while (ans < 0) ans += mod;
        printf("%lld\n",ans);
    }
    return 0;
}