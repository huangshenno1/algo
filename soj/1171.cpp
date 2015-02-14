#include <cstdio>

const int maxn = 110;
int T, t, n, a, b;
int x[maxn], y[maxn], dx, dy;
double s;

int Abs(int p) {return p>0 ? p : -p;}
int GCD(int p, int q) {return q==0 ? p : GCD(q, p%q);}

void CalArea()
{
    s = 0;
    for (int i = 1; i < n-1; i++)
        s += (x[i]-x[0])*(y[i+1]-y[0]) - (y[i]-y[0])*(x[i+1]-x[0]);
    s /= 2;
}

int main()
{
    scanf("%d",&T);
    for (t=1;t<=T;t++)
    {
        scanf("%d",&n);
        b = 0;
        x[0] = y[0] = 0;
        for (int i=0;i<n;i++)
        {
            scanf("%d%d",&dx,&dy);
            b += GCD(Abs(dx), Abs(dy));
            x[i+1] = x[i] + dx;
            y[i+1] = y[i] + dy;
        }
        CalArea();
        a = (int)((s+1-(double)b/2)+0.5);
        printf("Scenario #%d:\n",t);
        printf("%d %d %.1lf\n\n",a,b,s);
    }
    return 0;
}