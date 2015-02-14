#include <stdio.h>
#include <string.h>

int n,m,r;
bool a[150];
int p;
bool flag;

void Go()
{
    p=(p+1)%n;
    while (a[p])
        p=(p+1)%n;
}

void f(int k)
{
    k=(k-1)%r+1;
    while (k--)
        Go();
    a[p]=1;
    r--;
}

int main()
{
    while (scanf("%d",&n)==1 && n)
    {
        m=1;
        while (1)
        {
            flag=1;
            memset(a,0,sizeof(a));
            r=n-1;
            p=0;
            a[p]=1;
            while (r>1)
            {
                f(m);
                if (p==12)
                {
                    flag=0;
                    break;
                }
            }
            if (flag)
                break;
            m++;
        }
        printf("%d\n",m);
    }
    return 0;
}