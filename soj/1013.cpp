#include <cstdio>
#include <cmath>

int h,n,m,r,ans1,ans2;

int main()
{
    while (scanf("%d%d",&h,&m)==2 && (h||m))
    {
        if (m==1)
        {
            printf("0 %d\n",h);
            continue;
        }
        for (r=(int)(log(h*1.0)/log(2.0)+0.5);r>=1;r--)
        {
            n=(int)(pow(h*1.0,1.0/r)+0.5);
            if ((int)(pow(n*1.0,r*1.0)+0.5)==h && --n && (int)(pow(n*1.0,r*1.0)+0.5)==m)
            {
                ans1=(m-1)/(n-1);
                ans2=0;
                int t=1;
                while (1)
                {
                    ans2=ans2*n+t;
                    if (t==h) break;
                    t=t*(n+1);
                }
                printf("%d %d\n",ans1,ans2);
            }
        }
    }
    return 0;
}