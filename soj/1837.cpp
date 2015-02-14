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

const double eps = 1e-6;
const double pi = acos(-1.0);
double D,V;

double v(double d)
{
    double R = D/2, r = d/2;
    return R*R*D*pi - r*r*d*pi - (R*R+r*r+R*r)*(D-d)*pi/3;
}

int main()
{
    double d,low,high;
    while (scanf("%lf%lf",&D,&V)==2 && D>eps)
    {
        low = 0, high = D;
        while (low+eps < high)
        {
            d = (low+high)/2;
            if (v(d)>V) low=d;
            else high=d;
        }
        printf("%.3lf\n",low);
    }
    return 0;
}
