#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    for (int iCase=0;iCase<t;iCase++)
    {
        int n;
        scanf("%d",&n);
        int a[10],b[10];
        for (int i=0;i<n;i++)
            scanf("%d",&a[i]);
        for (int i=0;i<n;i++)
            scanf("%d",&b[i]);
        int s=0;
        for (int i=0;i<n;i++)
            s+=a[i]*b[i];
        printf("%d\n",s);
    }
    return 0;
}