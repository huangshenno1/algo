//计算几何

const double INF = 1e300;
const double eps = 1e-6;
const double PI = acos(-1.0);

//定义
struct Point
{
	double x, y;
	Point(double x=0, double y=0): x(x), y(y) {}
};
typedef Point Vector;

void print(Point p) {cout << p.x << " " << p.y << endl;}

//比较
bool operator < (const Point &a, const Point &b) {return a.x < b.x || (a.x == b.x && a.y <b.y);}
bool cmpy(const Point &a, const Point &b) {return a.y < b.y;}

int dcmp(double x) {if (fabs(x) < eps) return 0; else return x < 0 ? -1 : 1;}
bool operator == (const Point &a, const Point &b) {return dcmp(a.x-b.x) == 0 && dcmp(a.y-b.y) == 0;}
bool operator != (const Point &a, const Point &b) {return !(a == b);}

//基本运算
Vector operator + (Vector A, Vector B) {return Vector(A.x+B.x, A.y+B.y);}
Vector operator - (Vector A, Vector B) {return Vector(A.x-B.x, A.y-B.y);}
Vector operator * (Vector A, double p) {return Vector(A.x*p, A.y*p);}
Vector operator / (Vector A, double p) {return Vector(A.x/p, A.y/p);}

double Dot(Vector A, Vector B) {return A.x*B.x + A.y*B.y;}
double Cross(Vector A, Vector B) {return A.x*B.y - A.y*B.x;}

double Angle(Vector A) {return atan2(A.y, A.x);}
double Length(Vector A) {return sqrt(Dot(A, A));}
double Distance(Point A, Point B) {return sqrt(Dot(A-B, A-B));}
double _Angle(Vector A, Vector B) {return acos(Dot(A, B) / Length(A) / Length(B));}
double Angle(Vector A, Vector B) {return dcmp(Cross(B, A)) >= 0 ? _Angle(A, B) : -_Angle(A, B);}
double Area2(Point A, Point B, Point C) {return abs(Cross(B-A, C-A));}

Vector Rotate(Vector A, double rad) {return Vector(A.x*cos(rad)-A.y*sin(rad), A.x*sin(rad)+A.y*cos(rad));} //逆时针
Vector Normal(Vector A) {return Vector(-A.y/Length(A), A.x/Length(A));} //逆时针90
Point Translation(Point P, double rad, double dis) {return P + Rotate(Vector(1, 0), rad) * dis;}
Point _Reflection(Point P, Point A, Point B) {double rad = Angle(B-A, P-A); return A + Rotate(P-A, rad*2);}
Point Reflection(Point P, Point A, Point B)
{
	Vector v = B - A;
	Point Q = A + v*(Dot(v, P-A) / Dot(v, v));
	return Q + Q - P;
}

//在射线正向
bool OnPositiveSide(Point P, Point A, Point B)
{
	return dcmp(Dot(P-A, B-A)) > 0;	
}

//中垂线
void GetSegmentBisector(Point A, Point B, Point &C, Vector &v)
{
	C = (A + B) / 2;
	v = Normal(B - A);
}

Vector GetAngleBisector(Vector A, Vector B)
{
	return A/Length(A) + B/Length(B);
}

Point _GetLineIntersection(Point P, Vector v, Point Q, Vector w)
{
	Vector u = P - Q;
	double t = Cross(w, u) / Cross(v, w);
	return P + v*t;
}

Point GetLineIntersection(Point a1, Point a2, Point b1, Point b2)
{
	Vector v = a2-a1, w = b2-b1, u = a1-b1;
	double t = Cross(w, u) / Cross(v, w);
	return a1 + v*t;
}

Point GetLineIntersection2(Point a1, Point a2, Point b1, Vector b2)
{
	double d1 = Cross(a2-a1, b1-a1), d2 = Cross(a2-a1, b2-a1);
	return (b1*d2 - b2*d1) / (d2 - d1);
}

double DistanceToLine(Point P, Point A, Point B)
{
	Vector v1 = B - A, v2 = P - A;
	return fabs(Cross(v1, v2) / Length(v1));
}

double DistanceToSegment(Point P, Point A, Point B)
{
	if (A == B) return Length(P-A);
	Vector v1 = B - A, v2 = P - A, v3 = P - B;
	if (dcmp(Dot(v1, v2)) < 0) return Length(v2);
	else if (dcmp(Dot(v1, v3)) > 0) return Length(v3);
	else return fabs(Cross(v1, v2)) / Length(v1);
}

Point GetLineProjection(Point P, Point A, Point B)
{
	Vector v = B - A;
	return A + v*(Dot(v, P-A) / Dot(v, v));
}

bool SegmentLineIntersection(/*Segment*/Point a1, Point a2, /*Line*/Point b1, Point b2)
{
	double c1 = Cross(b2-a1, b2-b1), c2 = Cross(b2-a2, b2-b1);
	return dcmp(c1)*dcmp(c2)<0;
}

bool SegmentProperIntersection(Point a1, Point a2, Point b1, Point b2)
{
	double c1 = Cross(a2-a1, b1-a1), c2 = Cross(a2-a1, b2-a1), c3 = Cross(b2-b1, a1-b1), c4 = Cross(b2-b1, a2-b1);
	return dcmp(c1)*dcmp(c2)<0 && dcmp(c3)*dcmp(c4)<0;
}

bool OnSegment(Point P, Point A, Point B)
{
	return dcmp(Cross(A-P, B-P))==0 && dcmp(Dot(A-P, B-P))<0;
}

//多边形面积
double PolygonArea(Point *A, int n)
{
	if (n <= 2) return 0;
	double area = 0;
	for (int i = 1; i < n-1; i++)
		area += Cross(A[i]-A[0], A[i+1]-A[0]);
	return area/2;
}

//多边形周长
double PolygonPerimeter(Point *A, int n)
{
	double perimeter = 0;
	for (int i = 0; i < n; i++)
		perimeter += Length(A[(i+1)%n] - A[i]);
	return perimeter;
}

//点在多边形内
int IsPointInPolygon(Point P, Point *A, int n)
{
	int w = 0;
	for (int i = 0; i < n; i++)
	{
		if (OnSegment(P, A[i], A[(i+1)%n])) return -1;
		int k = dcmp(Cross(A[(i+1)%n]-A[i], P-A[i]));
		int d1 = dcmp(A[i].y - P.y);
		int d2 = dcmp(A[(i+1)%n].y - P.y);
		if (k>0 && d1<=0 && d2>0) w++;
		if (k<0 && d2<=0 && d1>0) w--;
	}
	if (w != 0) return 1;
	return 0;
}

//多边形重心
Point Gravitycenter(Point *A, int n)
{
	Point G(0, 0);
	double sum_area = 0;
	for (int i = 1; i < n-1; i++)
	{
		double area = Cross(A[i]-A[0], A[i+1]-A[0]);
		sum_area += area;
		G.x += area * (A[0].x + A[i].x + A[i+1].x);
		G.y += area * (A[0].y + A[i].y + A[i+1].y);
	}
	G.x /= 3 * sum_area;
	G.y /= 3 * sum_area;
	return G;
}

//三角形外心
Point Circumcenter(Point A, Point B, Point C)
{
	Point P, Q;
	Vector v, w;
	GetSegmentBisector(A, B, P, v);
	GetSegmentBisector(A, C, Q, w);
	return _GetLineIntersection(P, v, Q, w);	
}

//三角形内心
Point _Incenter(Point A, Point B, Point C)
{
	Vector v = GetAngleBisector(B-A, C-A), w = GetAngleBisector(A-B, C-B);
	return _GetLineIntersection(A, v, B, w);
}

Point Incenter(Point A, Point B, Point C)
{
	double a = Length(B-C), b = Length(A-C), c = Length(A-B);
	return (A*a + B*b + C*c) / (a + b + c);
}

//三角形垂心
Point Orthocenter(Point A, Point B, Point C)
{
	Point HA = GetLineProjection(A, B, C), HB = GetLineProjection(B, A, C);
	return GetLineIntersection(A, HA, B, HB);
}

//三角形费马点
Point FermatPoint(Point A, Point B, Point C)
{
	if (dcmp(_Angle(B-A, C-A) - PI/1.5) > 0) return A;
	if (dcmp(_Angle(A-B, C-B) - PI/1.5) > 0) return B;
	if (dcmp(_Angle(A-C, B-C) - PI/1.5) > 0) return C;
	double rad = dcmp(Cross(C-B, A-B)) >= 0 ? -PI/3 : PI/3;
	Point FA = B + Rotate(C-B, rad);
	rad = dcmp(Cross(C-A, B-A)) >= 0 ? -PI/3 : PI/3;
	Point FB = A + Rotate(C-A, rad);
	return GetLineIntersection(A, FA, B, FB);
}

//凸包
int ConvexHull(Point *A, int n, Point *ch)
{
	sort(A, A+n);
	int m = 0;
	for (int i = 0; i < n; i++)
	{
		while (m > 1 && Cross(ch[m-1]-ch[m-2], A[i]-ch[m-2]) <= 0) m--; // 不包含三点共线
		ch[m++] = A[i];
	}
	int k = m;
	for (int i = n-2; i >= 0; i--)
	{
		while (m > k && Cross(ch[m-1]-ch[m-2], A[i]-ch[m-2]) <= 0) m--; // 不包含三点共线
		ch[m++] = A[i];
	}
	if (n > 1) m--;
	return m;
}

//凸包直径平方
double RotatingCalipers(Point *ch,int n)
{
	int p = 1;
	double ans = 0;
	ch[n] = ch[0];
	for (int i = 0; i < n; i++)
	{
		while (abs(Cross(ch[p+1]-ch[i+1], ch[i]-ch[i+1])) > abs(Cross(ch[p]-ch[i+1], ch[i]-ch[i+1]))) p=(p+1)%n;
		ans = max(ans, max(Distance(ch[i], ch[p]), Distance(ch[i+1],ch[p+1]))); 
	}
	return ans;
}

//凸包相交，包括边界
bool IsConvexHullOverlap(Point *A, int n1, Point *B, int n2)
{
	for (int i = 0; i < n1; i++)
		for (int j = 0; j < n2; j++)
		{
			if (A[i] == B[j]) return 1;
			if (OnSegment(A[i], B[j], B[(j+1)%n2])) return 1;
			if (OnSegment(B[j], A[i], A[(i+1)%n1])) return 1;
			if (SegmentProperIntersection(A[i], A[(i+1)%n1], B[j], B[(j+1)%n2])) return 1;
			if (IsPointInPolygon(A[i], B, n2)) return 1;
			if (IsPointInPolygon(B[j], A, n1)) return 1;
		}
}

bool Between(Point P, Point A, Point B)
{
	return dcmp(Dot(A-P, B-P))<0;
}

//半平面交
int CutPolygon(Point *p, int n, Point A, Point B)
{
	Point q[maxn];
	int m = 0;
	for (int i = 0; i < n; i++)
	{
		Point C = p[i];
		Point D = p[(i+1)%n];
		if (dcmp(Cross(B-A, C-A)) >= 0) q[m++] = C;
		if (dcmp(Cross(B-A, C-D)) != 0)
		{
			Point E = GetLineIntersection(A, B, C, D);
			if (Between(E, C, D)) q[m++] = E;
		}
	}
	for (int i = 0; i < m; i++) p[i] = q[i];
	return m;
}

void _CutPolygon(Point *p, int n, Point *q, int &m, Point A, Point B)
{
	m = 0;
	for (int i = 0; i < n; i++)
	{
		Point C = p[i];
		Point D = p[(i+1)%n];
		if (dcmp(Cross(B-A, C-A)) >= 0) q[m++] = C;
		if (dcmp(Cross(B-A, C-D)) != 0)
		{
			Point E = GetLineIntersection(A, B, C, D);
			if (Between(E, C, D)) q[m++] = E;
		}
	}
}

//平面最近点对
double ClosestPair(int left, int right, Point *p)
{
    if (left == right) return INF;
    if (left + 1 == right) return Distance(p[left], p[right]);
    int mid = (left + right) >> 1;
    double ret = min(ClosestPair(left, mid, p), ClosestPair(mid+1, right, p));
    for (int i = left; i <= right; i++)
        for (int j = i+1; j <= i+7 && j <= right; j++)
            ret = min(ret, Distance(p[i], p[j]));
    return ret;
}
