#include <stdio.h>
#include <string.h>

int matrix[5][5]=
{
    {1,2,0,1,1},
    {1,1,0,0,0},
    {0,0,0,1,0},
    {1,0,1,0,0},
    {1,0,0,0,0}
};
int f[5][5];

void Mul_Matrix(int a[5][5],int b[5][5],int c[5][5],int mod)
{
    for (int i=0;i<5;i++)
    {
        for (int j=0;j<5;j++)
        {
            int s=0;
            for (int k=0;k<5;k++)
            {
                s=(s+a[i][k]*b[k][j])%mod;
            }
            c[i][j]=s;
        }
    }
}

void Mul(int n,int mod)
{
    if (n>1)
    {
        int temp[5][5];
        if (n&1)
        {
            Mul(n-1,mod);
            Mul_Matrix(f,matrix,temp,mod);
        }
        else
        {
            Mul(n>>1,mod);
            Mul_Matrix(f,f,temp,mod);
        }
        memcpy(f,temp,sizeof(f));
    }
    else
    {
        for (int i=0;i<5;i++)
        {
            for (int j=0;j<5;j++)
            {
                f[i][j]=matrix[i][j]%mod;
            }
        }
    }
}

int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)==2 && (n || m))
    {
        Mul(n,m);
        printf("%d\n",f[0][0]);
    }
    return 0;
}