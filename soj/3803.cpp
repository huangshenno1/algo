#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

ll mod = 7944288120LL;

int main()
{
    int T;
    ll k, powk[7];
    ll ans, ans1, ans2, ans3, ans4;
    cin >> T;
    while (T--)
    {
        cin >> k;
        powk[0] = 1;
        for (int i=1;i<=6;i++) powk[i] = (powk[i-1] * k) % mod;
        ans1 = powk[6];
        ans2 = powk[3] * 6 + powk[4] * 3;
        ans3 = powk[3] * 6;
        ans4 = powk[2] * 8;
        ans = ((ans1 + ans2 + ans3 + ans4) % mod) / 24;
        cout << ans << endl;
    }
    return 0;
}
