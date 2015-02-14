// #pragma comment(linker,"/STACK:102400000,102400000")
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;

const double eps = 1e-10;
const double PI = acos(-1.0);

struct Point
{
    double x, y;
    Point(double x=0, double y=0): x(x), y(y) {}
};
typedef Point Vector;

void print(Point p) {cout << p.x << " " << p.y << endl;}

int dcmp(double x) {if (fabs(x) < eps) return 0; else return x < 0 ? -1 : 1;}
bool operator == (const Point &a, const Point &b) {return dcmp(a.x-b.x) == 0 && dcmp(a.y-b.y) == 0;}
bool operator != (const Point &a, const Point &b) {return !(a == b);}

Vector operator + (Vector A, Vector B) {return Vector(A.x+B.x, A.y+B.y);}
Vector operator - (Vector A, Vector B) {return Vector(A.x-B.x, A.y-B.y);}
Vector operator * (Vector A, double p) {return Vector(A.x*p, A.y*p);}
Vector operator / (Vector A, double p) {return Vector(A.x/p, A.y/p);}

double Dot(Vector A, Vector B) {return A.x*B.x + A.y*B.y;}
double Cross(Vector A, Vector B) {return A.x*B.y - A.y*B.x;}

double Angle(Vector A) {return atan2(A.y, A.x);}
double Length(Vector A) {return sqrt(Dot(A, A));}
double Distance(Point A, Point B) {return sqrt(Dot(A-B, A-B));}
double Angle(Vector A, Vector B) {return acos(Dot(A, B) / Length(A) / Length(B));}
Vector Rotate(Vector A, double rad) {return Vector(A.x*cos(rad)-A.y*sin(rad), A.x*sin(rad)+A.y*cos(rad));}

Point GetLineIntersection(Point P, Vector v, Point Q, Vector w)
{
    Vector u = P - Q;
    double t = Cross(w, u) / Cross(v, w);
    return P + v*t;
}

double ACP(Point A, Point B, Point C, double x)
{
    Vector v1, v2;
    if (dcmp(Cross(A-B, C-B)) > 0)
    {
        v1 = Rotate(B-A, -x);
        v2 = Rotate(C-B, -x);
    }
    else
    {
        v1 = Rotate(B-A, x);
        v2 = Rotate(C-B, x);
    }
    Point p = GetLineIntersection(A, v1, B, v2);
    return Angle(A-C, p-C);
}

Point solve(Point A, Point B, Point C)
{
    double a = Angle(B-A, C-A), b = Angle(A-B, C-B), c = Angle(A-C, B-C);
    double low = 0, high = min(a, min(b, c)), mid, x;
    while (low + eps < high)
    {
        mid = (low + high) / 2;
        x = ACP(A, B, C, mid);
        if (dcmp(x - mid) == 0) break;
        else if (dcmp(x - mid) < 0) high = mid;
        else low = mid;
    }
    x = mid;
    Vector v1, v2;
    if (dcmp(Cross(A-B, C-B)) > 0)
    {
        v1 = Rotate(B-A, -x);
        v2 = Rotate(C-B, -x);
    }
    else
    {
        v1 = Rotate(B-A, x);
        v2 = Rotate(C-B, x);
    }
    return GetLineIntersection(A, v1, B, v2);
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    Point A, B, C, P, Q;
    while (scanf("%lf%lf%lf%lf%lf%lf",&A.x,&A.y,&B.x,&B.y,&C.x,&C.y) == 6)
    {
        if (dcmp(A.x)==0 && dcmp(A.y)==0 && dcmp(B.x)==0 && dcmp(B.y)==0 && dcmp(C.x)==0 && dcmp(C.y)==0) break;
        P = solve(A, B, C);
        Q = solve(B, A, C);
        printf("%.2lf %.2lf %.2lf %.2lf\n",P.x,P.y,Q.x,Q.y);
    }
    return 0;
}
