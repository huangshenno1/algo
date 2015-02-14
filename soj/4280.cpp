#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int T, n, l;
double xx1,xx2,yy1,yy2,r,d,alpha,beta;

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d%lf%lf%lf%lf%lf",&n,&l,&xx1,&yy1,&xx2,&yy2,&r);
        if (n==0)
        {
            printf("%d\n",0);
            continue;
        }
        d=sqrt((xx1-xx2)*(xx1-xx2)+(yy1-yy2)*(yy1-yy2));
        if (d<r)
        {
            printf("%d\n",(40+l*40)*n);
            continue;
        }
        alpha=asin(r/d)*2;
        beta=acos(-1)*2/n;
        printf("%d\n",(40+l*40)*(int)(alpha/beta+1));
    }
    return 0;
}