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

const int maxn = 100005;
ll base[10];
char input[maxn];
ll l, a, b, c;
ll ans1, ans2;

ll gcd(ll a, ll b) {return b == 0 ? a : gcd(b, a%b);}
void update(ll a, ll b){if (ans2 == -1 || b < ans2) {ans1 = a; ans2 = b;}}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    base[0] = 1;
    for (int i=1;i<=10;i++) base[i] = base[i-1] * 10;
    while (scanf("%s", input) == 1 && strcmp(input, "0") != 0)
    {
        l = strlen(input)-5;
        ans2 = -1;
        for (int i=1;i<=l;i++)
        {
            a = 0;
            for (int j=l+1,k=0,kk=0;j>=2;j--)
            {
                a += (input[j]-'0')*base[k++];
                if (j<l+2-i) a -= (input[j]-'0')*base[kk++];
            }
            b = base[l] - base[l-i];
            c = gcd(b, a);
            update(a/c, b/c);
        }
        printf("%lld/%lld\n", ans1, ans2);
    }
    return 0;
}
