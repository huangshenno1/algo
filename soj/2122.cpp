#include <stdio.h>

int a[500010]={0};
bool b[5000000]={0};

int main()
{
    for (int i=1;i<=500000;i++)
    {
        if (a[i-1]-i>0&&b[a[i-1]-i]==0)
        {
            a[i]=a[i-1]-i;
            b[a[i]]=1;
        }
        else
        {
            a[i]=a[i-1]+i;
            b[a[i]]=1;
        }
    }
    int    k;
    scanf("%d",&k);
    while (k!=-1)
    {
        printf("%d\n",a[k]);
        scanf("%d",&k);
    }
    return 0;
}