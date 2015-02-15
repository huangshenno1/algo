//3D计算几何

struct Point3
{
	double x, y, z;
	Point3(double x=0, double y=0, double z=0) : x(x), y(y), z(z) {}
	void TransPolar(double r, double phi, double theta)
	{
		x = r * sin(theta) * cos(phi);
		y = r * sin(theta) * sin(phi);
		z = r * cos(theta);
	}
	void TransCartesian(doublr &r, double &phi, double &theta)
	{
		r = sqrt(x*x + y*y + z*z);
		phi = atan2(y, x);
		theta = acos(z / r);
	}
};
typedef Point3 Vector3;

void print(Point3 p) {cout << p.x << " " << p.y << " " << p.z << endl;}

const double eps = 1e-6;
int dcmp(double x) {if (fabs(x) < eps) return 0; else return x < 0 ? -1 : 1;}
bool operator == (const Point3 &a, const Point3 &b) {return dcmp(a.x-b.x) == 0 && dcmp(a.y-b.y) == 0 && dcmp(a.z-b.z) == 0;}
bool operator != (const Point3 &a, const Point3 &b) {return !(a == b);}

Vector3 operator + (Vector3 A, Vector3 B) {return Vector3(A.x+B.x, A.y+B.y, A.z+B.z);}
Vector3 operator - (Vector3 A, Vector3 B) {return Vector3(A.x-B.x, A.y-B.y, A.z-B.z);}
Vector3 operator * (Vector3 A, double p) {return Vector3(A.x*p, A.y*p, A.z*p);}
Vector3 operator / (Vector3 A, double p) {return Vector3(A.x/p, A.y/p, A.z/p);}

double Dot(Vector3 A, Vector3 B) {return A.x*B.x + A.y*B.y + A.z*B.z;}
Vector3 Cross(Vector3 A, Vector3 B) {return Vector3(A.y*B.z - A.z*B.y, A.z*B.x - A.x*B.z, A.x*B.y - A.y*B.x);}
double Length(Vector3 A) {return sqrt(Dot(A, A));}
double Angle(Vector3 A, Vector3 B) {return acos(Dot(A, B) / Length(A) / Length(B));}
double Area2(Point3 A, Point3 B, Point3 C) {return Length(Cross(B-A, C-A));}
Vector3 Normal(Point3 A, Point3 B, Point3 C) {return Cross(B-A, C-A) / Length(B-A) / Length(C-A);}
bool IsZero(Point3 A) {return A == Vector3(0, 0, 0);}

bool OnLine(Point3 P, Point3 A, Point3 B)
{
	return IsZero(Cross(A-P, B-P));
}

bool OnSegment(Point3 P, Point3 A, Point3 B)
{
	return IsZero(Cross(A-P, B-P)) && dcmp(Dot(A-P, B-P)) < 0;
}

bool IsLineIntersection(Point3 a1, Point3 a2, Point3 b1, Point3 b2)
{
	if (IsZero(Cross(a2-a1, b2-b1))) return 0; //平行
	return IsZero(Dot(Cross(a2-a1, b1-a1), b2));
}

bool IsSegmentIntersection(Point3 a1, Point3 a2, Point3 b1, Point3 b2)
{
	if (!IsLineIntersection(a1, a2, b1, b2)) return 0;
	Vector3 tt = Cross(a1-a2, b1-b2), t1 = Cross(a2-a1, b1-a1), t2 = Cross(a2-a1, b2-a1), t3 = Cross(b2-b1, a1-b1), t4 = Cross(b2-b1, a2-b1);
	return dcmp(Dot(tt,t1)) * dcmp(Dot(tt,t2)) < 0 && dcmp(Dot(tt,t3)) * dcmp(Dot(tt,t4)) < 0;
}

Point3 Rotate(Point3 P, Vector3 v, double rad)
{
	double x = v.x, y = v.y, z = v.z, s = sin(rad), c = cos(rad);
	Point3 Q = Point3(
	(x*x*(1-c)+c)*P.x + (x*y*(1-c)-z*s)*P.y + (x*z*(1-c)+y*s)*P.z,
	(y*x*(1-c)+z*s)*P.x + (y*y*(1-c)+c)*P.y + (y*z*(1-c)-x*s)*P.z,
	(x*z*(1-c)-y*s)*P.x + (y*z*(1-c)+x*s)*P.y + (z*z*(1-c)+c)*P.z);
	return Q;
}

Point3 GetLineProjection(Point3 P, Point3 A, Point3 B)
{
	double t = Dot(P-A, B-A) / Length(B-A);
	return A + (B-A) / Length(B-A) * t;
}

Point3 GetLineReflection(Point3 P, Point3 A, Point3 B)
{
	Point3 PP = GetLineProjection(P, A, B);
	return PP + PP - P;
}

double DistanceToPlane(Point3 p, Point3 p0, Vector3 n)
{
	return fabs(Dot(p-p0, n)) / Length(n);
}

Point3 GetPlaneProjection(Point3 p, Point3 p0, Vector3 n)
{
	double d = Dot(p-p0, n) / Length(n);
	return p + n*d;
}

Point3 GetPlaneReflection(Point3 p, Point3 p0, Vector3 n)
{
	Point3 pp = GetPlaneProjection(p, p0, n);
	return pp + pp - p;
}

Point3 LinePlaneIntersection(Point3 p1, Point3 p2, Point3 p0, Vector3 n)
{
	Vector3 v = p2-p1;
	double t = Dot(p0-p1, n) / Dot(p2-p1, n); //判断分母是否为0
	return p1 + v*t; //如果是线段，判断t是不是在0到1之间
}

double DistanceToLine(Point3 P, Point3 A, Point3 B)
{
	Vector3 v1 = B-A, v2 = P-A;
	return Length(Cross(v1, v2)) / Length(v1);
}

double DistanceToSegment(Point3 P, Point3 A, Point3 B)
{
	if (A == B) return Length(P-A);
	Vector3 v1 = B-A, v2 = P-A, v3 = P-B;
	if (dcmp(Dot(v1, v2)) < 0) return Length(v2);
	else if (dcmp(Dot(v1, v3)) > 0) return Length(v2);
	else return Length(Cross(v1, v2)) / Length(v1);
}

Point3 LineDistancePoint3D(Point3 P1, Vector3 u, Point3 P2, Vector3 v)
{
    double b = Dot(Cross(u, v), Cross(u,v));
    double a = Dot(Cross(P2-P1, v), Cross(u,v));
    return P1 + u * (a/b);
}

double LineDistance3D(Point3 P1, Vector3 u, Point3 P2, Vector3 v)
{
    double b = Dot(u,u)*Dot(v,v) - Dot(u,v)*Dot(u,v);
    if (dcmp(b) == 0) return DistanceToLine(P1, P2, P2+v);
    double a = Dot(u,v)*Dot(v,P1-P2) - Dot(v,v)*Dot(u,P1-P2);
	return DistanceToLine(P1+u*(a/b), P2, P2+v);
}

void PlanePlaneIntersection(Point3 p1, Point3 n1, Point3 p2, Point3 n2)
{

}

// V = 1/6 * (OA x OB) . OC
double Volume6(Point3 A, Point3 B, Point3 C, Point3 D)
{
	return Dot(D-A, Cross(B-A, C-A));
}

// V2 = 1/36 * |a1 b1 c1|2 = 1/36 * |11 12 13|(a1a1+b1b1+c1c1)
//             |a2 b2 c2|           |12 22 23|
//             |a3 b3 c3|           |13 23 33|
double Volume6(double p, double q, double r, double n, double m, double l) //OA, OB, OC, AB, AC, BC
{
	double tmp1 = (p*p + q*q - n*n) / 2, tmp2 = (p*p + r*r - m*m) / 2, tmp3 = (q*q + r*r - l*l) / 2;
	//return sqrt(p*p*q*q*r*r + tmp1*tmp2*tmp3*2 - r*r*tmp1*tmp1 - q*q*tmp2*tmp2 - p*p*tmp3*tmp3);
	double t1 = p*p*q*q-tmp1*tmp1, t2 = tmp1*tmp3-q*q*tmp2, t3 = tmp1*tmp2-p*p*tmp3;
	return sqrt(t1*r*r + t2*tmp2 + t3*tmp3);
}

bool IsPointInTriangle(Point3 p, Point3 p1, Point3 p2, Point3 p3)
{
	double area1 = Area2(p, p1, p2);
	double area2 = Area2(p, p2, p3);
	double area3 = Area2(p, p3, p1);
	return dcmp(area1 + area2 + area3 - Area2(p1, p2, p3)) == 0;
}

bool TriLineIntersection(Point3 p1, Point3 p2, Point3 p3, Point3 A, Point3 B, Point3 &P)
{
	Vector3 n = Cross(p2-p1, p3-p1);
	if (dcmp(Dot(n, p1-A)) == 0) return 0; //平行
	else
	{
		double t = Dot(n, p1-A) / Dot(n, B-A);
		P = A + (B-A)*t;
		return IsPointInTriangle(P, p1, p2, p3); //点在三角形中
	}
}

bool TriSegIntersection(Point3 p1, Point3 p2, Point3 p3, Point3 A, Point3 B, Point3 &P)
{
	Vector3 n = Cross(p2-p1, p3-p1);
	if (dcmp(Dot(n, p1-A)) == 0) return 0; //平行
	else
	{
		double t = Dot(n, p1-A) / Dot(n, B-A);
		if (dcmp(t) < 0 || dcmp(t-1) > 0) return 0; //AB与平面p1p2p3不相交
		P = A + (B-A)*t;
		return IsPointInTriangle(P, p1, p2, p3); //点在三角形中
	}
}

bool TriTriIntersection(Point3 *T1, Point3 *T2)
{
	Point3 P;
	for (int i = 0; i < 3; i++)
	{
		if (TriSegIntersection(T1[0], T1[1], T1[2], T2[i], T2[(i+1)%3], P)) return true;
		if (TriSegIntersection(T2[0], T2[1], T2[2], T1[i], T1[(i+1)%3], P)) return true;
	}
	return false;
}

Point3 Circumcenter(Point3 A, Point3 B, Point3 C)
{
	Vector3 v1 = A-B, v2 = B-C, v3 = C-A;
	double t1 = - Dot(v2,v2) * Dot(v1,v3) / (2 * Dot(Cross(v1,v2),Cross(v1,v2)));
	double t2 = - Dot(v3,v3) * Dot(v1,v2) / (2 * Dot(Cross(v1,v2),Cross(v1,v2)));
	double t3 = - Dot(v1,v1) * Dot(v2,v3) / (2 * Dot(Cross(v1,v2),Cross(v1,v2)));
	return A*t1 + B*t2 + C*t3;
}

const int maxn = 110;
bool vis[maxn][maxn];

struct Face
{
	int v[3];
	Face (int a, int b, int c) {v[0]=a; v[1]=b; v[2]=c;}
	Vector3 Normal(Point3 *P) const
	{
		return Cross(P[v[1]]-P[v[0]], P[v[2]]-P[v[0]]);
	}
	int Cansee(Point3 *P, int i) const
	{
		return Dot(P[i]-P[v[0]], Normal(P)) > 0 ? 1 : 0;
	}
};

vector<Face> CH3D(Point3 *P, int n)
{
	vector<Face> cur;
	cur.push_back(Face(0,1,2));
	cur.push_back(Face(2,1,0));
	for (int i = 3; i < n; i++)
	{
		vector<Face> next;
		for (int j = 0; j < cur.size(); j++)
		{
			Face &f = cur[j];
			int res = f.Cansee(P, i);
			if (!res) next.push_back(f);
			for (int k = 0; k < 3; k++) vis[f.v[k]][f.v[(k+1)%3]] = res;
		}
		for (int j = 0; j < cur.size(); j++)
			for (int k = 0; k < 3; k++)
			{
				int a = cur[j].v[k], b = cur[j].v[(k+1)%3];
				if (vis[a][b] != vis[b][a] && vis[a][b]) next.push_back(Face(a,b,i));
			}
		cur = next;
	}
	return cur;
}

double rand01() {return rand() / (double)RAND_MAX;}
double randeps() {return (rand01() - 0.5) * eps;}
Point3 AddNoise(Point3 P) {return Point3(P.x+randeps(), P.y+randeps(), P.z+randeps());}

double PolyhedraSurfaceArea(Point3 *P, int n, Face *face, int m)
{
	double sarea = 0;
	for (int i = 0; i < m; i++)
		sarea += Area2(P[face[i].v[0]], P[face[i].v[1]], P[face[i].v[2]]);
	return sarea / 2;
}

double PolyhedraVolume(Point3 *P, int n, Face *face, int m)
{
	double volume = 0;
	Point3 O(0, 0, 0);
	for (int i = 0; i < m; i++)
		volume += Volume6(O, P[face[i].v[0]], P[face[i].v[1]], P[face[i].v[2]]);
	return fabs(volume / 6);
}

int IsPointInPolyhedra(Point3 p, Point3 *P, int n, Face *face, int m)
{
    Point3 A, B;
    Vector3 v(rand01(), rand01(), rand01());
    int i = 0;
	while (i < m)
	{
		if (IsPointInTriangle(p, P[face[i].v[0]], P[face[i].v[1]], P[face[i].v[2]])) return -1;
        if (TriLineIntersection(P[face[i].v[0]], P[face[i].v[1]], P[face[i].v[2]], p, p+v, A)) break;
        i++;
	}
	i++;
	while (i < m)
	{
		if (IsPointInTriangle(p, P[face[i].v[0]], P[face[i].v[1]], P[face[i].v[2]])) return -1;
        if (TriLineIntersection(P[face[i].v[0]], P[face[i].v[1]], P[face[i].v[2]], p, p+v, B)) break;
        i++;
	}
	if (i < m) return OnSegment(p ,A, B);
	return 0;
}

Point3 Gravitycenter(Point3 *P, int n, Face *face, int m)
{
	double volume = 0, v;
	Point3 G(0, 0, 0), g, O(0, 0, 0);
	for (int i = 0; i < m; i++)
	{
		g = (O + P[face[i].v[0]] + P[face[i].v[1]] + P[face[i].v[2]]) / 4;
		v = Volume6(O, P[face[i].v[0]], P[face[i].v[1]], P[face[i].v[2]]);
		if (dcmp(volume+v) == 0) v += eps;
		G = (G*volume + g*v) / (volume + v);
		volume += v;
	}	
	return G;
}

struct Sphere
{
	Point3 c;
	double r;
	Sphere(Point3 c, double r) : c(c), r(r) {}
	Sphere(Point3 A, Point3 B, Point3 C, Point3 D)
	{
		Point3 P1 = Circumcenter(A, B, C), P2 = Circumcenter(A, B, D);
		Vector3 n1 = Normal(A, B, C), n2 = Normal(A, B, D);
		double b = Dot(n1,n1)*Dot(n2,n2) - Dot(n1,n2)*Dot(n1,n2);
		double a = Dot(n1,n2)*Dot(n2,P1-P2) - Dot(n2,n2)*Dot(n1,P1-P2);
		c = P1 + n1 * (a / b);
		r = Length(c - A);
	}
};