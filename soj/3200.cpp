#include <stdio.h>

const int cost[10]={6,2,5,5,4,5,6,4,7,6};
const int ans[7]={1,1,2,2,2,6,8};
const int ans2[7]={0,0,0,0,0,0,8};

void f(int n)
{
    if (n<=0)
    {
        printf("\n");
        return;
    }
    int r=n%7;
    printf("%d",ans2[r]);
    f(n-cost[ans2[r]]);
}

int main()
{
    int t;
    int n,r;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        r=n%7;
        printf("%d",ans[r]);
        f(n-cost[ans[r]]);
    }
    return 0;
}