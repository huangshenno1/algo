#include <stdio.h>
#include <math.h>

int main()
{
    int t;
    int x;
    int ans;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&x);
        ans=log((double)((x+1)&(x^(x+1))))/log(2.0)+1.5;
        printf("%d\n",ans);
    }
}