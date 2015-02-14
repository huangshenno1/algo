#include <cstdio>
#include <cstring>
#include <cstdlib>
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

const double PI = acos(-1);
const double eps = 1e-8;
int T;
double r1,r2,h,v;
double low,mid,high,rr,vv;

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%lf%lf%lf%lf",&r1,&r2,&h,&v);
        low=0; high=h;
        while (low<high)
        {
            mid=(low+high)/2;
            rr=(r1*(h-mid)+r2*(mid-0))/h;
            vv=(r1*r1+r1*rr+rr*rr)*PI*mid/3;
            if (vv<v+eps && vv>v-eps) break;
            if (vv>v) high=mid;
            else low=mid;
        }
        printf("%.6lf\n",mid);
    }
    return 0;
}
