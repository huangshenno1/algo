#include <cstdio>
#include <algorithm>
using namespace std;

double Abs(double a) {return a>0?a:-a;}
double Max(double a, double b) {return a>b?a:b;}

struct Point
{
    double x, y;
    Point(double x=0, double y=0): x(x), y(y) {}
};
typedef Point Vector;

bool operator < (const Point &a, const Point &b) {return a.x < b.x || (a.x == b.x && a.y <b.y);}
Vector operator - (Vector A, Vector B) {return Vector(A.x-B.x, A.y-B.y);}
double Cross(Vector A, Vector B) {return A.x*B.y - A.y*B.x;}

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

double RotatingCalipers(Point *ch,int n)
{
    double ans = 0;
    int p = 1, q = 2;
    ch[n] = ch[0];
    for (int i = 0; i < n; i++)
    {
        while (Abs(Cross(ch[i]-ch[q+1], ch[i]-ch[p])) > Abs(Cross(ch[i]-ch[q], ch[i]-ch[p]))) q=(q+1)%n;
        ans = Max(ans, Abs(Cross(ch[i]-ch[q], ch[i]-ch[p])));
        while (Abs(Cross(ch[i]-ch[q], ch[i]-ch[p+1])) > Abs(Cross(ch[i]-ch[q], ch[i]-ch[p]))) p=(p+1)%n;
        ans = Max(ans, Abs(Cross(ch[i]-ch[q], ch[i]-ch[p])));
    }
    return ans/2;
}

const int maxn = 50010;
int n, m;
Point a[maxn], ch[maxn];

int main()
{
    while (scanf("%d",&n)==1 && n!=-1)
    {
        for (int i=0;i<n;i++) scanf("%lf%lf",&a[i].x,&a[i].y);
        m = ConvexHull(a,n,ch);
        double ans = RotatingCalipers(ch,m);
        printf("%.2lf\n",ans);
    }
    return 0;
}