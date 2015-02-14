#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cmath>
#include <cassert>
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

#define ll long long
#define pii pair<int, int>
#define fr first
#define sc second
#define mp make_pair
#define FOR(i,j,k) for(int i=j;i<=(k);i++)
#define FORD(i,j,k) for(int i=j;i>=(k);i--)
#define REP(i,n) for(int i=0;i<(n);i++)

const double eps = 1e-8;
int dcmp(double x) {if (fabs(x) < eps) return 0; return x < 0 ? -1 : 1;}
double x, y, z;

int judge()
{
    if (dcmp(x - 125) < 0 || dcmp(y - 90) < 0 || dcmp(z - 0.25) < 0 || dcmp(x + (y + z) * 2 - 2100) > 0) return 0;
    if (dcmp(x - 290) <= 0 && dcmp(y - 155) <= 0 && dcmp(z - 7) <= 0) return 1;
    if (dcmp(x - 380) <= 0 && dcmp(y - 300) <= 0 && dcmp(z - 50) <= 0) return 2;
    return 3;
}

int main()
{
    while (scanf("%lf%lf%lf", &x ,&y, &z) == 3)
    {
        if (dcmp(x) == 0 && dcmp(y) == 0 && dcmp(z) == 0) break;
        if (x < y) swap(x, y);
        if (x < z) swap(x, z);
        if (y < z) swap(y, z);
        int tmp = judge();
        if (tmp == 0) puts("not mailable");
        else if (tmp == 1) puts("letter");
        else if (tmp == 2) puts("packet");
        else puts("parcel");
    }
    return 0;
}
