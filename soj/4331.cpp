#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int a, b;
    while (scanf("%d%d", &a, &b) == 2)
    {
        if (a == b) {printf("%d %d 12:00\n", a, b); continue;}
        double tt = 12.0*3600.0*(24.0*3600.0-a) / abs(a-b);
        double tr = tt - (int)(tt/60.0)*60.0;
        ll t;
        if (tr < 30.0) t = ll(tt - tr + 0.5);
        else t = (ll)(tt - tr + 60.5);
        int hh = (t/3600)%12; if (hh == 0) hh = 12;
        int mm = (t%3600)/60;
        printf("%d %d %02d:%02d\n", a, b, hh, mm);
    }
    return 0;
}
