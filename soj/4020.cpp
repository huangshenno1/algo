#include <stdio.h>
#include <string.h>

int Abs(int a)
{
    return a>0?a:-a;
}

int main()
{
    int n,b;
    int num[100];
    bool f[5000];
    int i,j;
    bool flag;
    while (scanf("%d%d",&n,&b)==2 && (n||b))
    {
        memset(f,0,sizeof(f));
        f[0]=1;
        flag=1;
        for (i=0;i<b;i++)
            scanf("%d",&num[i]);
        for (i=0;i<b;i++)
            for (j=i+1;j<b;j++)
                f[Abs(num[i]-num[j])]=1;
        for (i=0;i<=n;i++)
        {
            if (f[i]==0)
            {
                flag=0;
                break;
            }
        }
        if (flag)
            printf("Y\n");
        else
            printf("N\n");
    }
    return 0;
}