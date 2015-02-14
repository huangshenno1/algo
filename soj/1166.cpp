#include <cstdio>

const int maxn = 1510;

struct Point
{
    double x, y;
    Point(double x=0, double y=0): x(x), y(y) {}
};
typedef Point Vector;

const double eps = 1e-6;
double Abs(double x) {return x>0?x:-x;}
int dcmp(double x) {if (Abs(x) < eps) return 0; else return x < 0 ? -1 : 1;}

Vector operator + (Vector A, Vector B) {return Vector(A.x+B.x, A.y+B.y);}
Vector operator - (Vector A, Vector B) {return Vector(A.x-B.x, A.y-B.y);}
Vector operator * (Vector A, double p) {return Vector(A.x*p, A.y*p);}

double Dot(Vector A, Vector B) {return A.x*B.x + A.y*B.y;}
double Cross(Vector A, Vector B) {return A.x*B.y - A.y*B.x;}

Point GetLineIntersection(Point P, Vector v, Point Q, Vector w)
{
    Vector u = P - Q;
    double t = Cross(w, u) / Cross(v, w);
    return P + v*t;
}

bool OnSegment(Point P, Point A, Point B)
{
    return dcmp(Cross(A-P, B-P))==0 && dcmp(Dot(A-P, B-P))<0;
}

int CutPolygon(Point *p, int n, Point A, Point B)
{
    Point q[maxn];
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        Point C = p[i];
        Point D = p[(i+1)%n];
        if (dcmp(Cross(B-A, C-A)) >= 0) q[m++] = C;
        if (dcmp(Cross(B-A, C-D)) != 0)
        {
            Point E = GetLineIntersection(A, B-A, C, D-C);
            if (OnSegment(E, C, D)) q[m++] = E;
        }
    }
    for (int i = 0; i < m; i++) p[i] = q[i];
    return m;
}

double PolygonArea(Point *A, int n)
{
    if (n <= 2) return 0;
    double area = 0;
    for (int i = 1; i < n-1; i++)
        area += Cross(A[i]-A[0], A[i+1]-A[0]);
    return Abs(area/2);
}

int T, n, m;
Point p[maxn], q[maxn];

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        m=n;
        for (int i=0;i<n;i++)
        {
            scanf("%lf%lf",&p[i].x,&p[i].y);
            q[i]=p[i];
        }
        for (int i=0;i<n;i++)
            m = CutPolygon(q,m,p[(i+1)%n],p[i]);
        double ans = PolygonArea(q,m);
        printf("%.2lf\n",ans);
    }
    return 0;
}