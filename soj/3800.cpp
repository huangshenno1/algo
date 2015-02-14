#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
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

const double eps = 1e-8;
const double g = 9.8;
int T;
double x,y,v;
double ans;

int main()
{
    double a,b,c;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%lf%lf%lf",&x,&y,&v);
        a=-0.5*g*x*x/v/v;
        b=x;
        c=a-y;
        if (b*b-4*a*c<0)
        {
            puts("-1");
            continue;
        }
        ans=atan((-b+sqrt(b*b-4*a*c))/(2*a));
        printf("%.6lf\n",ans);
    }
    return 0;
}
