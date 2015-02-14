#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int T,n,m,x1,x2,y1,y2,dx,dy;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d%d%d%d%d",&n,&m,&x1,&y1,&x2,&y2);
        dx=abs(x1-x2)-1; dy=abs(y1-y2)-1;
        if (dx==dy) printf("Shenfei\n");
        else printf("Dahema\n");
    }
    return 0;
}
