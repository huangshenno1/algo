#include <stdio.h>
#include <string.h>

int f[1000001];
bool e[10];

bool IsRepeat(int &x)
{
    int t,r;
    memset(e,0,sizeof(e));
    r=1;
    t=x;
    while (t)
    {
        r*=10;
        t/=10;
    }
    for (r/=10;r;r/=10)
    {
        t=(x/r)%10;
        if (e[t]==1)
        {
            x+=r;
            return 1;
        }
        e[t]=1;
    }
    return 0;
}

int main()
{
    for (int x=0,i=1;i<=1000000;i++)
    {
        x++;
        while (IsRepeat(x));
        f[i]=x;
    }
    int n;
    while (scanf("%d",&n)==1 && n)
    {
        printf("%d\n",f[n]);
    }
    return 0;
}