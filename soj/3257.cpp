#include <cstdio>
#include <cmath>

const double eps = 1e-6;
struct Point
{
    double x, y;
    Point(double x = 0, double y = 0): x(x), y(y) {}
};
typedef Point Vector;

int dcmp(double x) {if (fabs(x) < eps) return 0; else return x < 0 ? -1 : 1;}
Vector operator + (Vector A, Vector B) {return Vector(A.x+B.x, A.y+B.y);}
Vector operator - (Vector A, Vector B) {return Vector(A.x-B.x, A.y-B.y);}
Vector operator * (Vector A, double p) {return Vector(A.x*p, A.y*p);}
Vector operator / (Vector A, double p) {return Vector(A.x/p, A.y/p);}
double Dot(Vector A, Vector B) {return A.x*B.x + A.y*B.y;}
double Cross(Vector A, Vector B) {return A.x*B.y - A.y*B.x;}
double Length(Vector A) {return sqrt(Dot(A, A));}
Vector Normal(Vector A) {return Vector(-A.y/Length(A), A.x/Length(A));}

bool OnSegment(Point P, Point A, Point B)
{
    return dcmp(Cross(A-P, B-P))==0 && dcmp(Dot(A-P, B-P))<=0;
}

int IsPointInPolygon(Point P, Point *A, int n)
{
    int w = 0;
    for (int i = 0; i < n; i++)
    {
        if (OnSegment(P, A[i], A[(i+1)%n])) return 0;
        int k = dcmp(Cross(A[(i+1)%n]-A[i], P-A[i]));
        int d1 = dcmp(A[i].y - P.y);
        int d2 = dcmp(A[(i+1)%n].y - P.y);
        if (k>0 && d1<=0 && d2>0) w++;
        if (k<0 && d2<=0 && d1>0) w--;
    }
    if (w != 0) return 1;
    return 0;
}

bool SegmentProperIntersection(Point a1, Point a2, Point b1, Point b2)
{
    double c1 = Cross(a2-a1, b1-a1), c2 = Cross(a2-a1, b2-a1), c3 = Cross(b2-b1, a1-b1), c4 = Cross(b2-b1, a2-b1);
    return dcmp(c1)*dcmp(c2)<0 && dcmp(c3)*dcmp(c4)<0;
}

Point a[20], b[20];
int n, m;

bool check()
{
    a[n] = a[0]; b[m] = b[0];
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            if (SegmentProperIntersection(a[i], a[i+1], b[j], b[j+1])) return 1;
    Point p;
    Vector v;
    for (int i=0;i<n;i++)
    {
        v = Normal(a[i+1] - a[i]);
        p = (a[i] + a[i+1]) / 2 + v / 1000;
        if (IsPointInPolygon(p, b, m)) return 1;
    }
    for (int i=0;i<m;i++)
    {
        v = Normal(b[i+1] - b[i]);
        p = (b[i] + b[i+1]) / 2 + v / 1000;
        if (IsPointInPolygon(p, a, n)) return 1;
    }
    return 0;
}

int main()
{
    while (scanf("%d%d", &n, &m) == 2)
    {
        for (int i=0;i<n;i++) scanf("%lf%lf", &a[i].x, &a[i].y);
        for (int i=0;i<m;i++) scanf("%lf%lf", &b[i].x, &b[i].y);
        if (check()) puts("YES");
        else puts("NO");
    }
    return 0;
}
