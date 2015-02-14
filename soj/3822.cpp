#pragma comment(linker,"/STACK:102400000,102400000")
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

int n, a[1010], ans1, ans2;

int main()
{
    while (scanf("%d", &n) == 1)
    {
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        ans2 = 0;
        for (int i = 1; i <= n; i++) ans2 += a[i];
        sort(a+1, a+n+1);
        if (a[n] * 3 >= ans2)
        {
            ans1 = a[n];
            printf("%d %d\n", ans1, ans2);
            continue;
        }
        ans1 = ans2 / 3;
        if (ans2 % 3) ans1++;
        printf("%d %d\n", ans1, ans2);
    }
    return 0;
}
