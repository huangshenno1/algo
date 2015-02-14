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
//typedef long long ll;

int m, p, l, e, r, s, n;

void f()
{
    int mm = p/s, pp = l/r, ll = m*e;
    m = mm; p = pp; l = ll;
}

int main()
{
    while (scanf("%d%d%d%d%d%d%d", &m, &p, &l, &e, &r, &s, &n) == 7)
    {
        for (int i=0;i<n;i++) f();
        printf("%d\n", m);
    }
    return 0;
}
