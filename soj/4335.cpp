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

int n, x, y, a, b, ans;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    while (scanf("%d/%d", &x, &n) == 2)
    {
        ans = 0;
        for (x=n+1;x<=n*2;x++)
        {
            a = x-n; b = n*x;
            if (b%a == 0) ans ++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
