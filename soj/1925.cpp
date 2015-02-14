#include <stdio.h>
#include <math.h>

int main()
{
    int D[41]={1},R[41]={1};
    for (int i=1;i<=40;i++)
    {
        for (int k=1;k<=i;k++)
        {
            D[i]+=R[i-k]/k;
            R[i]+=ceil((double)D[i-k]/k);
        }
    }
    int n;
    scanf("%d",&n);
    while (n!=-1)
    {
        printf("%d\n",D[n]);
        scanf("%d",&n);
    }
    return 0;
}