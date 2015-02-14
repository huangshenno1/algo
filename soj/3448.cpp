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

const int mod = 512;
int s[100010][10];
int n, k;

int main()
{
    memset(s, 0, sizeof(s));
    for (int i=1;i<=100000;i++) s[i][1] = 1;
    for (int i=2;i<=100000;i++)
        for (int j=2;j<=10;j++)
            s[i][j] = (s[i-1][j-1] + j * s[i-1][j]) % mod;
    while (scanf("%d%d", &k, &n) == 2)
    {
        int ans = 0;
        for (int i=1;i<=k;i++)
            ans = (ans + s[n][i]) % mod;
        printf("%d\n", ans);
    }
    return 0;
}
