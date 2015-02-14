#include <cstdio>
#include <algorithm>
using namespace std;

struct Point
{
    long long x, y;
    Point(long long x=0, long long y=0): x(x), y(y) {}
};
typedef Point Vector;

bool operator < (const Point &a, const Point &b) {return a.x < b.x || (a.x == b.x && a.y <b.y);}
Vector operator - (Vector A, Vector B) {return Vector(A.x-B.x, A.y-B.y);}
long long Cross(Vector A, Vector B) {return A.x*B.y - A.y*B.x;}

int ConvexHull(Point *A, int n, Point *ch)
{
    sort(A, A+n);
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        while (m > 1 && Cross(ch[m-1]-ch[m-2], A[i]-ch[m-2]) < 0) m--;
        ch[m++] = A[i];
    }
    int k = m;
    for (int i = n-2; i >= 0; i--)
    {
        while (m > k && Cross(ch[m-1]-ch[m-2], A[i]-ch[m-2]) < 0) m--;
        ch[m++] = A[i];
    }
    if (n > 1) m--;
    return m;
}

const int maxn = 100010;
int n, n1, n2;
Point a[maxn], b[maxn];
long long x, y;
char ch[3];

int main()
{
    while (scanf("%d",&n)==1)
    {
        n1=0;
        while (n--)
        {
            scanf("%lld %lld %s",&x,&y,ch);
            if (ch[0]=='N') continue;
            a[n1++]=Point(x,y);
        }
        n2=ConvexHull(a,n1,b);
        printf("%d\n",n2);
        for (int i=0;i<n2;i++) printf("%lld %lld\n",b[i].x,b[i].y);
    }
    return 0;
}