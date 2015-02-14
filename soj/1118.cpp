#include <stdio.h>

int main()
{
    int sum_k_a[100]={0,1,1},sum_k_b[100]={0,0,0};
    int up_k_a[100]={0,1,0},up_k_b[100]={0,0,1};
    int down_k_a[100]={0,0,0},down_k_b[100]={0,0,1};
    int a,b,n,m,x;
    int i;
    scanf("%d%d%d%d",&a,&n,&m,&x);
    for (i=3;i<n;i++)
    {
        up_k_a[i]=up_k_a[i-1]+up_k_a[i-2];
        up_k_b[i]=up_k_b[i-1]+up_k_b[i-2];
        down_k_a[i]=up_k_a[i-1];
        down_k_b[i]=up_k_b[i-1];
        sum_k_a[i]=sum_k_a[i-1]+up_k_a[i]-down_k_a[i];
        sum_k_b[i]=sum_k_b[i-1]+up_k_b[i]-down_k_b[i];
    }
    b=(m-a*sum_k_a[n-1])/sum_k_b[n-1];
    printf("%d\n",a*sum_k_a[x]+b*sum_k_b[x]);
    return 0;
}