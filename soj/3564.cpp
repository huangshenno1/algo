#include <cstdio>
#include <algorithm>
using namespace std;

const double PI = 3.141592653;

int main()
{
    int T,n,r;
    int v[25],s;
    double l;
    int i;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&r);
        l=2*PI*r;
        for (i=0;i<n;i++)
            scanf("%d",&v[i]);
        sort(v,v+n);
        for (i=0,s=0;i<n-1;i++)
            s+=v[i+1]-v[i];
        if (s==0) printf("Inf\n");
        else printf("%.3lf\n",l/s);
    }
    return 0;
}