#include <stdio.h>

#define N 1000

long long fa[N+10],na;
long long fb[N+10],nb;

int Min(int a,int b)
{
    return a<b?a:b;
}

int main()
{
    int i,j,k;
    long long a,b,ta,tb;
    int minn;
    bool flag;
    while (scanf("%lld%lld",&a,&b)==2 && (a||b))
    {
        fa[0]=ta=a;
        fb[0]=tb=b;
        na=0;
        nb=0;
        while (1)
        {
            if (ta==1||na>=N)
                break;
            if (ta&1)
                ta=3*ta+1;
            else ta/=2;
            fa[++na]=ta;
        }
        while (1)
        {
            if (tb==1||nb>=N)
                break;
            if (tb&1)
                tb=3*tb+1;
            else tb/=2;
            fb[++nb]=tb;
        }
        minn=Min(na,nb);
        flag=0;
        k=0;
        while (k<=minn)
        {
            for (j=0;j<=k;j++)
                if (fa[k]==fb[j])
                {
                    i=k;
                    flag=1;
                    break;
                }
            if (flag)
                break;
            for (i=0;i<=k;i++)
                if (fa[i]==fb[k])
                {
                    j=k;
                    flag=1;
                    break;
                }
            if (flag)
                break;
            k++;
        }
        if (k>minn)
        {
            flag=0;
            if (na>nb)
            {
                for (i=nb+1;i<=na;i++)
                {
                    for (j=0;j<=nb;j++)
                        if (fa[i]==fb[j])
                        {
                            flag=1;
                            break;
                        }
                    if (flag)
                        break;
                }
            }
            else if (na<nb)
            {
                for (j=na+1;j<=nb;j++)
                {
                    for (i=0;i<=na;i++)
                        if (fa[i]==fb[j])
                        {
                            flag=1;
                            break;
                        }
                    if (flag)
                        break;
                }
            }
        }
        printf("%lld needs %d steps, %lld needs %d steps, they meet at %lld\n",a,i,b,j,fa[i]);
    }
    return 0;
}