#include <stdio.h>

int main()
{
    int n,m,j,x;
    int l,r;
    int temp;
    int ans;
    while (scanf("%d%d%d",&n,&m,&j)==3)
    {
        ans=0;
        l=1;
        r=m;
        while (j--)
        {
            scanf("%d",&x);
            if (x>r)
            {
                temp=x-r;
                r+=temp;
                l+=temp;
                ans+=temp;
            }
            else if (x<l)
            {
                temp=l-x;
                l-=temp;
                r-=temp;
                ans+=temp;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}