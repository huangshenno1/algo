#include <stdio.h>

int abs(int n)
{
    return n<0?-n:n;
}

int max(int a,int b)
{
    return a>b?a:b;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int iCase=0;iCase<t;iCase++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        int r=max(abs(x),abs(y));
        int s=4*r*r+4*r;
        if (y==-r)
        {
            s=s-r+x;
        }
        else if (x==-r)
        {
            s=s-3*r-y;
        }
        else if (y==r)
        {
            s=s-5*r-x;
        }
        else
        {
            s=s-7*r+y;
        }
        printf("%d\n",s);
    }
    return 0;
}