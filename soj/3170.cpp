#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    for (int iCase=0;iCase<t;iCase++)
    {
        int x1,y1,x2,y2,x3,y3,x4,y4;
        scanf("%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);

        if (x1>=x4||x2<=x3||y1>=y4||y2<=y3)
            printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}