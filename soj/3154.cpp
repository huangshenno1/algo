#include <stdio.h>

int max_w;

void Pick(int i,int n,int c,int cw,int w[])
{
    if (cw>max_w)
        max_w=cw;
    if (i==n)
        return;
    if (c-cw>=w[i])
        Pick(i+1,n,c,cw+w[i],w);
    Pick(i+1,n,c,cw,w);
}

int main()
{
    int c,n;
    int w[20];
    int i;
    while (scanf("%d%d",&c,&n)==2)
    {
        max_w=0;
        for (i=0;i<n;i++)
            scanf("%d",&w[i]);
        Pick(0,n,c,0,w);
        printf("%d\n",max_w);
    }
    return 0;
}