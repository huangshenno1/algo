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

long long f(int n, int m)
{
    if ((n&1) && (m&1)) return 1 + 4 * f(n/2, m/2);
    return 0;
}

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        cout << f(n, m) << endl;
    }
    return 0;
}
