#include <stdio.h>

int GCD(int a,int b)
{
    return b==0?a:GCD(b,a%b);
}

int Abs(int a)
{
    return a>=0?a:-a;
}

int main()
{
    int s,c,p,l;
    int r,m;
    int iCase=1;
    while (scanf("%d%d%d%d",&s,&c,&p,&l)==4 && (s||c||p||l))
    {
        if (Abs(l-p)%GCD(s,c)!=0)
        {
            printf("Case %d: Never\n",iCase++);
            continue;
        }
        m=(s-p)%s;
        r=0;
        while (l<=p || (l+m)%c!=0)
        {
            l+=s;
            r++;
        }
        printf("Case %d: %d %d/%d\n",iCase++,r,m,s);
    }
    return 0;
}