#include <cstdio>
#include <cmath>

struct Point
{
    double x, y;
    Point(double x=0, double y=0): x(x), y(y) {}
};
typedef Point Vector;

const double eps = 1e-6;
int dcmp(double x) {if (fabs(x) < eps) return 0; else return x < 0 ? -1 : 1;}
bool operator == (const Point &a, const Point &b) {return dcmp(a.x-b.x) == 0 && dcmp(a.y-b.y) == 0;}

Vector operator + (Vector A, Vector B) {return Vector(A.x+B.x, A.y+B.y);}
Vector operator - (Vector A, Vector B) {return Vector(A.x-B.x, A.y-B.y);}
Vector operator * (Vector A, double p) {return Vector(A.x*p, A.y*p);}
Vector operator / (Vector A, double p) {return Vector(A.x/p, A.y/p);}

double Dot(Vector A, Vector B) {return A.x*B.x + A.y*B.y;}
double Length(Vector A) {return sqrt(Dot(A, A));}
double Cross(Vector A, Vector B) {return A.x*B.y - A.y*B.x;}

double DistanceToLine(Point P, Point A, Point B)
{
    if (A == B) return Length(P-A);
    Vector v1 = B - A, v2 = P - A, v3 = P - B;
    if (dcmp(Dot(v1,v2)) < 0) return Length(v2);
    else if (dcmp(Dot(v1,v3)) > 0) return Length(v3);
    else return fabs(Cross(v1, v2) / Length(v1));
}

int main()
{
    double x1,y1,x2,y2,x3,y3;
    while (scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3)==6)
    {
        Point A(x1,y1),B(x2,y2),C(x3,y3);
        double dis = DistanceToLine(C, A, B);
        printf("%.2lf\n",dis);
    }
    return 0;
}