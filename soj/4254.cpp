#include <cstdio>

const int mod = 20121223;

struct Matrix
{
    long long elem[3][3];
    Matrix(long long a=0, long long b=0, long long c=0, long long d=0, long long e=0, long long f=0, long long g=0, long long h=0, long long i=0)
    {
        elem[0][0] = a;
        elem[0][1] = b;
        elem[0][2] = c;
        elem[1][0] = d;
        elem[1][1] = e;
        elem[1][2] = f;
        elem[2][0] = g;
        elem[2][1] = h;
        elem[2][2] = i;
    }
};

Matrix mul(Matrix a, Matrix b)
{
    Matrix c;
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            for (int k=0;k<3;k++)
                c.elem[i][j]=(c.elem[i][j]+a.elem[i][k]*b.elem[k][j])%mod;
    return c;
}

Matrix pow(Matrix a, int n)
{
    Matrix c(3,1,1,0,0,0,0,0,0);
    while (n)
    {
        if (n&1) c=mul(c,a);
        a=mul(a,a);
        n>>=1;
    }
    return c;
}

int T,n;

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        if (n==0) {printf("1\n"); continue;}
        Matrix a(3,1,0,2,0,0,1,0,1);
        Matrix c = pow(a, n-1);
        long long ans = c.elem[0][0];
        printf("%lld\n",ans);
    }
    return 0;
}