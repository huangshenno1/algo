#include <stdio.h>
#include <math.h>

int amount[1000010];
int camount[1000010];

int IsPrime(int n)
{
    if (n==0||n==1)
        return 0;
    int temp=sqrt(n);
    int i;
    if (n==2)
        return 1;
    if (n%2==0)
        return 0;
    for (i=3;i<=temp;i+=2)
    {
        if (n%i==0)
            return 0;
    }
    return 1;
}

int LowBit(int n)
{
    return (n^(n-1))&n;
}

void Change(int p,int add,int n)
{
    int temp=IsPrime(amount[p]+add)-IsPrime(amount[p]);
    amount[p]+=add;
    while (p<=n)
    {
        camount[p]+=temp;
        p+=LowBit(p);
    }
}

int Sum(int p)
{
    int s=0;
    while (p>0)
    {
        s+=camount[p];
        p-=LowBit(p);
    }
    return s;
}

void Init(int n)
{
    int i;
    for (i=1;i<=n;i++)
    {
        camount[i]=IsPrime(amount[i]);
    }
    for (i=1;i<n;i++)
    {
        if (i+LowBit(i)<=n)
            camount[i+LowBit(i)]+=camount[i];
    }
}

int main()
{
    int c,n,m;
    int cmd,x,y;
    int iCase=1,i;
    while (scanf("%d%d%d",&c,&n,&m)==3)
    {
        if (c==0 && n==0 && m==0)
            break;
        printf("CASE #%d:\n",iCase++);
        for (i=1;i<=c;i++)
            amount[i]=m;
        Init(c);
        for (i=0;i<n;i++)
        {
            scanf("%d%d%d",&cmd,&x,&y);
            if (cmd==0)
            {
                Change(x,y,c);
            }
            else
            {
                printf("%d\n",Sum(y)-Sum(x-1));
            }
        }
        printf("\n");
    }
    return 0;
}
