#include <cstdio>

struct Point
{
    int x, y;
    Point(int x=0, int y=0): x(x), y(y) {}
};
typedef Point Vector;

int Cross(Vector A, Vector B) {return A.x*B.y - A.y*B.x;}
Vector operator - (Vector A, Vector B) {return Vector(A.x-B.x, A.y-B.y);}
bool OnRight(Point P, Point A, Point B) {return Cross(B-A, P-A)>0;}

int n, m, x1, y1, x2, y2;
Point a[5010], b[5010], p;
int ans[5010];

void init()
{
    for (int i=0;i<=n;i++) ans[i]=0;
    for (int i=0;i<=n+1;i++) {a[i].y=y1; b[i].y=y2;}
    a[0].x=b[0].x=x1; a[n+1].x=b[n+1].x=x2;
    for (int i=1;i<=n;i++)
        scanf("%d%d",&a[i].x,&b[i].x);
}

int main()
{
    int low,high,mid;
    while (scanf("%d",&n)==1 && n)
    {
        scanf("%d%d%d%d%d",&m,&x1,&y1,&x2,&y2);
        init();
        while (m--)
        {
            scanf("%d%d",&p.x,&p.y);
            low=0,high=n;
            while (low<=high)
            {
                mid=(low+high)>>1;
                if (OnRight(p,a[mid],b[mid]))
                {
                    if (OnRight(p,a[mid+1],b[mid+1])) low=mid+1;
                    else break;
                }
                else high=mid-1;
            }
            ans[mid]++;
        }
        for (int i=0;i<=n;i++) printf("%d: %d\n",i,ans[i]);
        printf("\n");
    }
    return 0;
}