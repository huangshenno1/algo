#include <stdio.h>

int stack[1000001];
int p;
int energe[1000001];
int x[1000001];

int main()
{
    int n;
    int i;
    while (scanf("%d",&n)==1)
    {
        for (i=1;i<=n;i++)
            scanf("%d",&x[i]);
        p=-1;
        for (i=n;i>=0;i--)
        {
            while (p!=-1)
            {
                if (stack[p]>x[i])
                {
                    energe[i]=stack[p];
                    stack[++p]=x[i];
                    break;
                }
                p--;
            }
            if (p==-1)
            {
                stack[++p]=x[i];
                energe[i]=0;
            }
        }
        for (i=1;i<=n;i++)
            printf("%d\n",energe[i]);
    }
    return 0;
}