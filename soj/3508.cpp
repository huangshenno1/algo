#include <cstdio>
#include <cstring>
#include <cctype>
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
typedef long long ll;

int n, x, t;

int main()
{
    while (scanf("%d%d", &n, &x) == 2)
    {
        t = 1 << (n-1);
        while (1)
        {
            if (x == t) break;
            if (x > t) x = t - x + t;
            n--; t >>= 1;
        }
        printf("%d\n", n);
    }
    return 0;
}
