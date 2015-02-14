#include <stdio.h>
#include <math.h>
void main()
{
    int r1,r2,x1,x2,x3,y1,y2,y3,z1,z2,z3;
    int a,b;
    int n,i;
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        scanf("%d%d%d%d%d%d%d%d%d%d%d",&x1,&y1,&z1,&r1,&x2,&y2,&z2,&r2,&x3,&y3,&z3);
        a=(x1-x3)*(x1-x3)+(y1-y3)*(y1-y3)+(z1-z3)*(z1-z3);
        b=(x3-x2)*(x3-x2)+(y3-y2)*(y3-y2)+(z3-z2)*(z3-z2);
        if (a>r1*r1&&b>r2*r2)
        {
            printf("No\n");
            continue;
        }
        if (r1*r1-a==r2*r2-b)
            printf("No\n");
        else printf("Yes\n");
    }
}