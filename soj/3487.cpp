#include <cstdio>
#include <algorithm>
using namespace std;

struct Point
{
    int x, y;
    Point(int x=0, int y=0): x(x), y(y) {}
};
typedef Point Vector;

bool operator < (const Point &a, const Point &b) {return a.x < b.x || (a.x == b.x && a.y <b.y);}
Vector operator - (Vector A, Vector B) {return Vector(A.x-B.x, A.y-B.y);}
int Cross(Vector A, Vector B) {return A.x*B.y - A.y*B.x;}

int ConvexHull(Point *A, int n, Point *ch)
{
    sort(A, A+n);
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        while (m > 1 && Cross(ch[m-1]-ch[m-2], A[i]-ch[m-2]) <= 0) m--;
        ch[m++] = A[i];
    }
    int k = m;
    for (int i = n-2; i >= 0; i--)
    {
        while (m > k && Cross(ch[m-1]-ch[m-2], A[i]-ch[m-2]) <= 0) m--;
        ch[m++] = A[i];
    }
    if (n > 1) m--;
    return m;
}

const int maxn = 1010;
int T, t, n, m;
Point a[maxn], ch[maxn];

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&t,&n);
        for (int i=0;i<n;i++) scanf("%d%d",&a[i].x,&a[i].y);
        m = ConvexHull(a,n,ch);
        int st=0, mx=ch[0].x, my=ch[0].y;
        for (int i=1;i<m;i++)
            if ((ch[i].y==my && ch[i].x<mx) || ch[i].y>my) {st=i; mx=ch[i].x; my=ch[i].y;}
        printf("%d %d\n",t,m);
        for (int i=st;i>=0;i--) printf("%d %d\n",ch[i].x,ch[i].y);
        for (int i=m-1;i>st;i--) printf("%d %d\n",ch[i].x,ch[i].y);
    }
    return 0;
}