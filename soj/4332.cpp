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

const int maxn = 6005;
struct Doll
{
    int w, c;
    bool operator<(const Doll &dd) const {return w+c>dd.w+dd.c;}
}doll[maxn];
int dp[maxn];
int n, ans, a, b;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    while (scanf("%d%d", &a, &b) == 2)
    {
        n = 1;
        doll[n].w = a; doll[n].c = b-a;
        while (scanf("%d%d", &a, &b) == 2 && (a||b))
        {
            n++;
            doll[n].w = a; doll[n].c = b-a;
        }
        sort(doll+1, doll+n+1);
        memset(dp, -1, sizeof(dp));
        for (int i=1;i<=n;i++)
        {
            for (int j=i;j>=2;j--)
                dp[j] = max(dp[j], min(dp[j-1]-doll[i].w, doll[i].c));
            dp[1] = max(dp[1], doll[i].c);
        }
        for (int i=n;i>=1;i--)
            if (dp[i] >= 0)
            {
                ans = i;
                break;
            }
        printf("%d\n", ans);
    }
    return 0;
}
