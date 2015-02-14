#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

int ans[100000], tot;

int main()
{
    int n, nn;
    while (scanf("%d", &n) == 1)
    {
        nn = sqrt((double)n);
        tot = 0;
        for (int i=1;i<=nn;i++)
            if (n % i == 0)
            {
                ans[tot++] = i;
                ans[tot++] = n/i;
            }
        if (tot >= 2 && ans[tot-2] == ans[tot-1]) tot--;
        sort(ans, ans+tot);
        for (int i=tot-1;i>=0;i--) printf("%d\n", ans[i]);
        puts("");
    }
    return 0;
}
