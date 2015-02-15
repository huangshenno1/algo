struct Point
{
	double x, y;
	Point(double x=0, double y=0): x(x), y(y) {}
};
typedef Point Vector;

bool operator < (const Point &a, const Point &b) {return a.x < b.x || (a.x == b.x && a.y <b.y);}
Vector operator - (Vector A, Vector B) {return Vector(A.x-B.x, A.y-B.y);}
double Cross(Vector A, Vector B) {return A.x*B.y - A.y*B.x;}

double Dot(Vector A, Vector B) {return A.x*B.x + A.y*B.y;}
double Distance(Point A, Point B) {return sqrt(Dot(A-B, A-B));}

int ConvexHull(Point *A, int n, Point *ch)
{
	sort(A, A+n);
	int m = 0;
	for (int i = 0; i < n; i++)
	{
		while (m > 1 && Cross(ch[m-1]-ch[m-2], A[i]-ch[m-2]) <= 0) m--;
		ch[m++] = A[i];
	}
	int k = m;
	for (int i = n-2; i >= 0; i--)
	{
		while (m > k && Cross(ch[m-1]-ch[m-2], A[i]-ch[m-2]) <= 0) m--;
		ch[m++] = A[i];
	}
	if (n > 1) m--;
	return m;
}

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