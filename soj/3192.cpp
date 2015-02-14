#include <stdio.h>

int min(int a,int b)
{
    return a<b?a:b;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int iCase=0;iCase<t;iCase++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        int steps=min(x,y/2);
        x=x-steps;
        y=y-2*steps;
        steps=steps*2+x+y;
        printf("%d\n",steps);
    }
    return 0;
}