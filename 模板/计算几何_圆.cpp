//计算几何_圆

struct Point
{
    double x, y;
    Point(double x=0, double y=0) : x(x), y(y) {}
};
typedef Point Vector;

void print(Point p) {cout << p.x << " " << p.y << endl;}

int dcmp(double x) {if (fabs(x) < eps) return 0; return x < 0 ? -1 : 1;}
bool operator == (const Point &a, const Point &b) {return dcmp(a.x-b.x) == 0 && dcmp(a.y-b.y) == 0;}
Vector operator + (Vector A, Vector B) {return Vector(A.x+B.x, A.y+B.y);}
Vector operator - (Vector A, Vector B) {return Vector(A.x-B.x, A.y-B.y);}
Vector operator * (Vector A, double k) {return Vector(A.x*k, A.y*k);}
Vector operator / (Vector A, double k) {return Vector(A.x/k, A.y/k);}
double Dot(Vector A, Vector B) {return A.x*B.x + A.y*B.y;}
double Cross(Vector A, Vector B) {return A.x*B.y - A.y*B.x;}
double Angle(Vector A) {return atan2(A.y, A.x);}
double Length(Vector A) {return sqrt(A.x*A.x + A.y*A.y);}

void GetSegmentBisector(Point A, Point B, Point &C, Vector &v)
{
	C = (A + B) / 2;
	v = Normal(B - A);
}

Point _GetLineIntersection(Point P, Vector v, Point Q, Vector w)
{
	Vector u = P - Q;
	double t = Cross(w, u) / Cross(v, w);
	return P + v*t;
}

struct Line
{
    Point p;
    Vector v;
    Line(Point p, Vector v) : p(p), v(v) {}
    Point point(double t) {return p + v*t;}
};

struct Circle
{
    Point c;
    double r;
	Circle() {c = Point(0, 0); r = 0;}
    Circle(Point c, double r) : c(c), r(r) {}
	Circle(Point A, Point B, Point C)
	{
		Point P, Q;
		Vector v, w;
		GetSegmentBisector(A, B, P, v);
		GetSegmentBisector(A, C, Q, w);
		c = _GetLineIntersection(P, v, Q, w);
		r = Length(A - c);
	}
    Point point(double a) {return Point(c.x + r*cos(a), c.y + r*sin(a));}
};

int _GetLineCircleIntersection(Line L, Circle C, double &t1, double &t2, vector<Point> &sol)
{
    double a = L.v.x, b = L.p.x-C.c.x, c = L.v.y, d = L.p.y-C.c.y;
    double e = a*a+c*c, f = 2*(a*b+c*d), g = b*b+d*d-C.r*C.r;
    double delta = f*f - 4*e*g;
    if (dcmp(delta) < 0) return 0;
    else if (dcmp(delta) == 0)
    {
        t1 = t2 = -f / (2*e); sol.push_back(L.point(t1));
        return 1;
    }
    else
    {
        t1 = (-f - sqrt(delta)) / (2*e); sol.push_back(L.point(t1));
        t2 = (-f + sqrt(delta)) / (2*e); sol.push_back(L.point(t2));
        return 2;
    }
}

int GetLineCircleIntersection(Point A, Point B, Circle C, double &t1, double &t2, vector<Point> &sol)
{
    double a = (B-A).x, b = A.x-C.c.x, c = (B-A).y, d = A.y-C.c.y;
    double e = a*a+c*c, f = 2*(a*b+c*d), g = b*b+d*d-C.r*C.r;
    double delta = f*f - 4*e*g;
    if (dcmp(delta) < 0) return 0;
    else if (dcmp(delta) == 0)
    {
        t1 = t2 = -f / (2*e); sol.push_back(A + (B-A)*t1);
        return 1;
    }
    else
    {
        t1 = (-f - sqrt(delta)) / (2*e); sol.push_back(A + (B-A)*t1);
        t2 = (-f + sqrt(delta)) / (2*e); sol.push_back(A + (B-A)*t2);
        return 2;
    }
}

int GetCircleCircleIntersection(Circle C1, Circle C2, double &t1, double &t2, vector<Point> &sol)
{
    double d = Length(C2.c - C1.c);
    if (dcmp(d) == 0)
    {
        if (dcmp(C2.r - C1.r) == 0) return -1; //两圆重合
        return 0;
    }
    if (dcmp(C1.r + C2.r - d) < 0) return 0;
    if (dcmp(fabs(C2.r - C1.r) - d) > 0) return 0;
    double a = Angle(C2.c - C1.c);
    double da = acos((C1.r*C1.r + d*d - C2.r*C2.r) / (2*C1.r*d));
    t1 = a - da; t2 = a + da;
    Point p1 = C1.point(t1), p2 = C1.point(t2);
    sol.push_back(p1);
    if (p1 == p2) return 1;
    sol.push_back(p2);
    return 2;
}

int GetTangentPoint(Point p, Circle C, double &t1, double &t2, vector<Point> &sol)
{
    double d = Length(p - C.c);
    if (dcmp(d - C.r) < 0) return 0;
    if (dcmp(d - C.r) == 0)
    {
        t1 = t2 = Angle(p - C.c);
        sol.push_back(C.point(t1));
        return 1;
    }
    double a = Angle(p - C.c);
    double da = acos(C.r / d);
    t1 = a - da; t2 = a + da;
    sol.push_back(C.point(t1));
    sol.push_back(C.point(t2));
    return 2;
}

int GetTangentPoint(Circle C1, Circle C2, vector<Point> &sol1, vector<Point> &sol2)
{
    int cnt = 0;
    if (dcmp(C1.r - C2.r) < 0) {swap(C1, C2); swap(sol1, sol2);}
    double d = Length(C1.c - C2.c);
    double rdiff = fabs(C1.r - C2.r), rsum = C1.r + C2.r;
    if (dcmp(d - rdiff) < 0) return 0; //内含
    if (dcmp(d) == 0 && C1.r == C2.r) return -1; //两圆重合，无数多条切线
    double a = Angle(C2.c - C1.c);
	if (dcmp(d - rdiff) == 0) //内切
	{
		sol1.push_back(C1.point(a)); sol2.push_back(C2.point(a)); cnt++;
		return 1;
	}
	//有外公切线
	double da = acos(rdiff / d);
	sol1.push_back(C1.point(a+da)); sol2.push_back(C2.point(a+da)); cnt++;
	sol1.push_back(C1.point(a-da)); sol2.push_back(C2.point(a-da)); cnt++;
	if (dcmp(d - rsum) == 0) //一条内公切线
	{
		sol1.push_back(C1.point(a)); sol2.push_back(C2.point(PI+a)); cnt++;
	}
	else if (dcmp(d - rsum) > 0) //两条外公切线
	{
		da = acos(rsum / d);
		sol1.push_back(C1.point(a+da)); sol2.push_back(C2.point(PI+a+da)); cnt++;
		sol1.push_back(C1.point(a-da)); sol2.push_back(C2.point(PI+a-da)); cnt++;
	}
	return cnt;
}

double CircleOverlapArea(Circle C1, Circle C2)
{
	double d = Length(C1.c - C2.c);
	if (C1.r + C2.r <= d) return 0;
	if (C2.r - C1.r >= d) return PI * C1.r * C1.r;
	if (C1.r - C2.r >= d) return PI * C2.r * C2.r;
	double a = acos((C1.r*C1.r+d*d-C2.r*C2.r) / (2*C1.r*d));
	double b = acos((C2.r*C2.r+d*d-C1.r*C1.r) / (2*C2.r*d));
	return a*C1.r*C1.r + b*C2.r*C2.r - C1.r*sin(a)*d;
}

double CircleUnionArea(Circle *C, int n)
{

}