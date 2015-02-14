#include <stdio.h>

typedef struct  
{
    int a,b,c,d;
}Matrix;

Matrix Multiply(Matrix A,Matrix B)
{
    Matrix C;
    C.a=((A.a*B.a)%7+(A.b*B.c)%7)%7;
    C.b=((A.a*B.b)%7+(A.b*B.d)%7)%7;
    C.c=((A.c*B.a)%7+(A.d*B.c)%7)%7;
    C.d=((A.c*B.b)%7+(A.d*B.d)%7)%7;
    return C;
}

Matrix A,B;

int f(int n)
{
    if (n==0||n==-1)
        return 1;
    while (n)
    {
        Matrix temp=A;
        if (n%2)
        {
            A=Multiply(temp,B);
        }
        temp=B;
        B=Multiply(temp,temp);
        n/=2;
    }
    return A.a;
}

int main()
{
    int a,b,n;
    while (scanf("%d%d%d",&a,&b,&n))
    {
        if (a==0 && b==0 && n==0)
            break;
        A.a=1;A.b=1;A.c=0;A.d=0;
        B.a=a;B.b=1;B.c=b;B.d=0;
        printf("%d\n",f(n-2));
    }
    return 0;
}