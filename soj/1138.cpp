#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct Point
{
    double x, y;
    Point(double x=0, double y=0): x(x), y(y) {}
};
typedef Point Vector;

bool operator < (const Point &a, const Point &b) {return a.x < b.x || (a.x == b.x && a.y <b.y);}
Vector operator - (Vector A, Vector B) {return Vector(A.x-B.x, A.y-B.y);}
double Dot(Vector A, Vector B) {return A.x*B.x + A.y*B.y;}
double Cross(Vector A, Vector B) {return A.x*B.y - A.y*B.x;}
double Distance(Point A, Point B) {return sqrt(Dot(A-B, A-B));}

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

int n, m;
Point a[maxn],b[maxn];
double l, ans;

int main()
{
    while (scanf("%d%lf",&n,&l)==2)
    {
        for (int i=0;i<n;i++) scanf("%lf%lf",&a[i].x,&a[i].y);
        m = ConvexHull(a,n,b);
        ans = 2*3.14159265359*l + Distance(b[0],b[m-1]);
        for (int i=1;i<m;i++)
            ans += Distance(b[i-1],b[i]);
        printf("%.0lf\n",ans);
    }
    return 0;
}