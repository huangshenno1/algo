#include <stdio.h>
#include <string.h>

struct COW
{
    int h,v;
    int no;
};

COW cow[50001];
COW stack[50001];
int p;
int hearing[50001];

int main()
{
    int max;
    int n;
    int i;
    while (scanf("%d",&n)==1)
    {
        memset(hearing,0,sizeof(hearing));
        for (i=1;i<=n;i++)
        {
            scanf("%d%d",&cow[i].h,&cow[i].v);
            cow[i].no=i;
        }
        p=-1;
        for (i=1;i<=n;i++)
        {
            while (p!=-1)
            {
                if (cow[i].h<stack[p].h)
                {
                    hearing[stack[p].no]+=cow[i].v;
                    stack[++p]=cow[i];
                    break;
                }
                p--;
            }
            if (p==-1)
                stack[++p]=cow[i];
        }
        p=-1;
        for (i=n;i>=1;i--)
        {
            while (p!=-1)
            {
                if (cow[i].h<stack[p].h)
                {
                    hearing[stack[p].no]+=cow[i].v;
                    stack[++p]=cow[i];
                    break;
                }
                p--;
            }
            if (p==-1)
                stack[++p]=cow[i];
        }
        max=0;
        for (i=1;i<=n;i++)
        {
            if (hearing[i]>max)
                max=hearing[i];
        }
        printf("%d\n",max);
    }
    return 0;
}