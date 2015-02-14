#include <stdio.h>

int main()
{
    int p,q;
    while (scanf("%d%d",&p,&q)==2)
    {
        int fp[3010],fq[3010];
        int cp=0,cq=0;
        for (int i=1;i<=p/2;i++)
        {
            if (!(p%i))
            {
                fp[cp++]=i;
            }
        }
        fp[cp++]=p;
        for (int i=1;i<=q/2;i++)
        {
            if (!(q%i))
            {
                fq[cq++]=i;
            }
        }
        fq[cq++]=q;
        for (int i=0;i<cp;i++)
        {
            for (int j=0;j<cq;j++)
            {
                printf("%d %d\n",fp[i],fq[j]);
            }
        }
    }
    return 0;
}