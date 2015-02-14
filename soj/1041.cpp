#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
using namespace std;

//定义
struct Point
{
    double x, y;
    Point(double x=0, double y=0): x(x), y(y) {}
};
typedef Point Vector;

//比较
bool operator < (const Point &a, const Point &b) {return a.x < b.x || (a.x == b.x && a.y <b.y);}

const double eps = 1e-3;
int dcmp(double x) {if (fabs(x) < eps) return 0; else return x < 0 ? -1 : 1;}
bool operator == (const Point &a, const Point &b) {return dcmp(a.x-b.x) == 0 && dcmp(a.y-b.y) == 0;}

//基本运算
Vector operator + (Vector A, Vector B) {return Vector(A.x+B.x, A.y+B.y);}
Vector operator - (Vector A, Vector B) {return Vector(A.x-B.x, A.y-B.y);}
Vector operator * (Vector A, double p) {return Vector(A.x*p, A.y*p);}
Vector operator / (Vector A, double p) {return Vector(A.x/p, A.y/p);}

double Dot(Vector A, Vector B) {return A.x*B.x + A.y*B.y;}
double Cross(Vector A, Vector B) {return A.x*B.y - A.y*B.x;}

double Length(Vector A) {return sqrt(Dot(A, A));}
double Distance(Point A, Point B) {return sqrt(Dot(A-B, A-B));}

bool OnLine(Point P, Point A, Point B)
{
    return dcmp(Cross(A-P, B-P))==0;
}

bool SegmentProperIntersection(Point a1, Point a2, Point b1, Point b2)
{
    double c1 = Cross(a2-a1, b1-a1), c2 = Cross(a2-a1, b2-a1);
    return dcmp(c1)*dcmp(c2)<=0;
}

Point GetLineIntersection(Point a1, Point a2, Point b1, Point b2)
{
    if (OnLine(b1,a1,a2)) return b1;
    if (OnLine(b2,a1,a2)) return b2;
    if (!SegmentProperIntersection(a1,a2,b1,b2)) return Point(-1e300,0);
    Vector v = a1-a2, w = b1-b2, u = a1-b1;
    double t = Cross(w, u) / Cross(v, w);
    return a1 + v*t;
}

int n;
double ans,x[22],y[22];
Point up[22],down[22];
bool flag;

int main()
{
    while (scanf("%d",&n)==1 && n)
    {
        for (int i=1;i<=n;i++)
        {
            scanf("%lf%lf",&x[i],&y[i]);
            up[i].x=down[i].x=x[i];
            up[i].y=y[i]; down[i].y=y[i]-1;
        }
        ans=-1e300;
        flag=0;
        for (int i=1;i<n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                if (i==j) continue;
                int k;
                for (k=1;k<=n;k++)
                    if (!SegmentProperIntersection(up[i],down[j],up[k],down[k])) break;
                if (k>n) {flag=1; break;}
                if (k>max(i,j))
                {
                    double tmp=GetLineIntersection(up[i],down[j],up[k],up[k-1]).x;
                    if (ans<tmp) ans=tmp;
                    tmp=GetLineIntersection(up[i],down[j],down[k],down[k-1]).x;
                    if (ans<tmp) ans=tmp;
                }
            }
            if (flag) break;
        }
        if (flag) puts("Through all the pipe.");
        else printf("%.2lf\n",ans);
    }
    return 0;
}