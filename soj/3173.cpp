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

const int maxn = 1000005;
int T, a, b, ans, cnt;
int dp[maxn];

int main()
{
    memset(dp, 0, sizeof(dp));
    for (int i=1;i<=1000;i++)
    {
        dp[i*i]++;
        for (int j=i+1;i*j<maxn;j++)
            dp[i*j] += 2;
    }

    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &a, &b);
        cnt = 0;
        for (int i=a;i<=b;i++)
            if (dp[i] > cnt)
            {
                ans = i;
                cnt = dp[i];
            }
        printf("%d\n", ans);
    }
    return 0;
}
