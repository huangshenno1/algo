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

int k, n, ans;

int num(int x)
{
    if (x == 0) return 1;
    if (x == 1) return 6;
    if (x == 2) return 9;
}

int main()
{
    while (scanf("%d", &k) == 1)
    {
        k --;
        ans = 0;
        n = 1;
        int b = 3;
        while (k >= b)
        {
            k -= b;
            n ++;
            b *= 3;
        }
        b = 1;
        for (int i=0;i<n;i++)
        {
            ans += b * num(k % 3);
            k /= 3;
            b *= 10;
        }
        printf("%d\n", ans);
    }
    return 0;
}
