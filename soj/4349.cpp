#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cmath>
#include <iostream>
#include <sstream>
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
typedef long long ll;

const int maxn = 1010;
ll a[maxn], b[maxn];
ll x, y, xx, yy, ans1, ans2, ans;
int na, nb;

int main()
{
    while (scanf("%lld%lld", &x, &y) == 2 && x)
    {
        xx = x; yy = y;
        a[0] = x; b[0] = y;
        na = nb = 1;
        while (1)
        {
            if (x == 1 || na >= maxn) break;
            if (x & 1) x = 3*x+1;
            else x = x/2;
            a[na++] = x;
        }
        while (1)
        {
            if (y == 1 || nb >= maxn) break;
            if (y & 1) y = 3*y+1;
            else y = y/2;
            b[nb++] = y;
        }
        ans1 = ans2 = 1LL << 62;
        for (int i=0;i<na;i++)
            for (int j=0;j<nb;j++)
                if (a[i] == b[j])
                {
                    if (max(i, j) < max(ans1, ans2))
                    {
                        ans1 = i;
                        ans2 = j;
                        ans = a[i];
                    }
                }
        printf("%lld needs %lld steps, %lld needs %lld steps, they meet at %lld\n", xx, ans1, yy, ans2, ans);
    }
    return 0;
}
