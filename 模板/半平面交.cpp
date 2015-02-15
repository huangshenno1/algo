struct Point
{
	double x, y;
	Point(double x=0, double y=0): x(x), y(y) {}
};
typedef Point Vector;

void print(Point p) {cout << p.x << " " << p.y << endl;}

const double eps = 1e-6;
int dcmp(double x) {if (fabs(x) < eps) return 0; else return x < 0 ? -1 : 1;}

Vector operator + (Vector A, Vector B) {return Vector(A.x+B.x, A.y+B.y);}
Vector operator - (Vector A, Vector B) {return Vector(A.x-B.x, A.y-B.y);}
Vector operator * (Vector A, double p) {return Vector(A.x*p, A.y*p);}

double Dot(Vector A, Vector B) {return A.x*B.x + A.y*B.y;}
double Cross(Vector A, Vector B) {return A.x*B.y - A.y*B.x;}

//Point GetLineIntersection(Point P, Vector v, Point Q, Vector w)
//{
//	Vector u = P - Q;
//	double t = Cross(w, u) / Cross(v, w);
//	return P + v*t;
//}

Point GetLineIntersection(Point a1, Point a2, Point b1, Vector b2)
{
	Vector v = a1-a2, w = b1-b2, u = a1-b1;
	double t = Cross(w, u) / Cross(v, w);
	return a1 + v*t;
}

bool OnSegment(Point P, Point A, Point B)
{
	return dcmp(Cross(A-P, B-P))==0 && dcmp(Dot(A-P, B-P))<0;
}

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
			if (OnSegment(E, C, D)) q[m++] = E;
		}
	}
	for (int i = 0; i < m; i++) p[i] = q[i];
	return m;
}