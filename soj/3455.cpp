//#pragma comment(linker,"/STACK:102400000,102400000")
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
typedef long long ll;

int n;

ll f(ll x)
{
    if (x <= 1) return x;
    return ((x + 1) / 2) * ((x + 1) / 2) + f(x / 2);
}

int main()
{
    while (scanf("%d", &n) == 1)
    {
        printf("%lld\n", f(n));
    }
    return 0;
}
